Multi-Threaded Web Server in C++ Overview This project implements a basic multi-threaded web server in C++ that handles multiple client requests concurrently. It is designed to serve static HTML files. The server listens on port [8080] (http://localhost:8080/) by default and processes each client request in a separate thread.

Features Multi-threading: Each client request is handled by a separate thread using the C++ Standard Library's std::thread. Socket Programming: The server uses the Winsock API for network communication. Static File Serving: The server responds with the content of index.html or a 404 Not Found page if the file does not exist. Basic HTTP Response: The server responds with a simple HTTP 200 OK response for valid requests.

Prerequisites Windows OS (The server uses the Winsock API, which is specific to Windows). C++ Compiler: Make sure your environment has a C++ compiler that supports C++11 or higher. Winsock2 Library: The project links against the Ws2_32.lib library.

How It Works ->Initialize Winsock: The server starts by initializing Winsock using WSAStartup. ->Create Server Socket: A server socket is created using the socket() function, and it is bound to an IP address and port using the bind() function. Close Connections: Once the response is sent, the server closes the client socket.

File Structure server.cpp: The main server code which is task4.cpp, index.html: The default HTML file served by the server.
