#include <iostream>
#include <thread>
#include <string>
#include <fstream>
#include <winsock2.h>
#include <ws2tcpip.h>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

#define PORT 8080

bool initialize_winsock() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        cout << "WSAStartup failed with error: " << result << endl;
        return false;
    }
    return true;
}

void cleanup_winsock() {
    WSACleanup();
}

string get_html_content(const string& path) {
     ifstream file(path);
    if (!file.is_open()) {
        return "<html><body><h1>404 Not Found</h1></body></html>";
    }
    return string((istreambuf_iterator<char>(file)),
       istreambuf_iterator<char>());
}


void handle_client(SOCKET client_socket) {
    char buffer[1024] = { 0 };
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
       cout << "Request received:\n" << buffer << endl;

       
        string header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";

       string html_content = get_html_content("index.html");
       string response = header + html_content;

        send(client_socket, response.c_str(), response.length(), 0);
    }

    closesocket(client_socket);
}

SOCKET create_server_socket() {
    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        cout << "Socket creation failed with error: " << WSAGetLastError() << endl;
        cleanup_winsock();
        exit(EXIT_FAILURE);
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        cout << "Bind failed with error: " << WSAGetLastError() << endl;
        closesocket(server_socket);
        cleanup_winsock();
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed with error: " << WSAGetLastError() << endl;
        closesocket(server_socket);
        cleanup_winsock();
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

void server_loop(SOCKET server_socket) {
    cout << "Server is listening on port " << PORT << "...\n";

    while (true) {
        sockaddr_in client_address;
        int client_address_len = sizeof(client_address);
        SOCKET client_socket = accept(server_socket, (sockaddr*)&client_address, &client_address_len);

        if (client_socket == INVALID_SOCKET) {
            cerr << "Accept failed with error: " << WSAGetLastError() << endl;
            continue;
        }
        thread client_thread(handle_client, client_socket);
        client_thread.detach();  
    }
}

int main() {
    if (!initialize_winsock()) {
        return 1;
    }

    SOCKET server_socket = create_server_socket();

    server_loop(server_socket);

    closesocket(server_socket);
    cleanup_winsock();

    return 0;
}
