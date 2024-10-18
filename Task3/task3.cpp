
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string compressRLE(const string& input) {
    string compressed = "";
    int length = input.length();

    for (int i = 0; i < length; ++i) {
        int count = 1;

        while (i + 1 < length && input[i] == input[i + 1]) {
            ++count;
            ++i;
        }

        compressed += input[i];
        compressed += to_string(count);
    }

    return compressed;
}

string decompressRLE(const string& input) {
    string decompressed = "";
    int length = input.length();

    for (int i = 0; i < length; ++i) {
   
        char ch = input[i];
        ++i;
        int count = input[i] - '0';

    
        decompressed.append(count, ch);
    }

    return decompressed;
}

void compressFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cout << "Error: Could not open the input file!" << endl;
        return;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cout << "Error: Could not open the output file!" << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inputFile)),
        istreambuf_iterator<char>());

    string compressedContent = compressRLE(content);
    outputFile << compressedContent;

    inputFile.close();
    outputFile.close();
    cout << "File compressed successfully." << endl;
}

// Function to decompress file
void decompressFile(const string& inputFileName, const string& outputFileName) {
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cout << "Error: Could not open the input file!" << endl;
        return;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cout << "Error: Could not open the output file!" << endl;
        return;
    }

    string compressedContent((istreambuf_iterator<char>(inputFile)),
        istreambuf_iterator<char>());

    string decompressedContent = decompressRLE(compressedContent);
    outputFile << decompressedContent;

    inputFile.close();
    outputFile.close();
    cout << "File decompressed successfully." << endl;
}

int main() {
    int choice;
    string inputFileName, outputFileName;

    cout << "File Compression and Decompression Tool" << endl;
    cout << "1. Compress a file" << endl;
    cout << "2. Decompress a file" << endl;
    cout << "Enter your choice (1/2): ";
    cin >> choice;

    cout << "Enter the input file name: ";
    cin >> inputFileName;

    cout << "Enter the output file name: ";
    cin >> outputFileName;

    if (choice == 1) {
        compressFile(inputFileName, outputFileName);
    }
    else if (choice == 2) {
        decompressFile(inputFileName, outputFileName);
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
