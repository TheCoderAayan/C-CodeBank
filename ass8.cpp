#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileEncryptor {
private:
    string filename;
    int encryptionKey;

public:
    FileEncryptor(string fn, int eK) {
        filename = fn;
        encryptionKey = eK;
    }

    void encryptAndWrite(string message) {
        string encrypted = "";

        for (char c : message) {
            if (isalpha(c)) {
                if (c == 'Z') c = 'A';
                else if (c == 'z') c = 'a';
                else c = c + 1;
            }
            encrypted += c;
        }

        ofstream outfile(filename);
        if (outfile.is_open()) {
            outfile << encrypted;
            outfile.close();
            cout << "Encrypted message written to file." << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void readAndDecrypt() {
        string decrypted = "";
        string line;

        ifstream infile(filename);
        if (infile.is_open()) {
            getline(infile, line);
            for (char c : line) {
                if (isalpha(c)) {
                    if (c == 'A') c = 'Z';
                    else if (c == 'a') c = 'z';
                    else c = c - 1;
                }
                decrypted += c;
            }
            infile.close();
            cout << "Decrypted message: " << decrypted << endl;
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }

    void displayFileContents() {
        string line;
        ifstream myfile(filename);
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                cout << line << endl;
            }
            myfile.close();
        } else {
            cout << "Unable to open file to display contents." << endl;
        }
    }
};

int main() {
    FileEncryptor fe("data.txt", 1);
    int choice;
    string message;

    do {
        cout << "\n--- File Encryptor Menu ---\n";
        cout << "1. Add string and encrypt\n";
        cout << "2. Decrypt from file\n";
        cout << "3. Display file contents\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To ignore leftover newline after cin

        switch (choice) {
            case 1:
                cout << "Enter message to encrypt: ";
                getline(cin, message);
                fe.encryptAndWrite(message);
                break;

            case 2:
                fe.readAndDecrypt();
                break;

            case 3:
                cout << "Encrypted file contents:\n";
                fe.displayFileContents();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}


