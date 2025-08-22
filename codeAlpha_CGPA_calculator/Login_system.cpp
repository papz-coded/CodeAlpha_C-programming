#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to check if username already exists
bool userExists(string username) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// Function to register user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists. Please try another one.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream file("users.txt", ios::app); // open file in append mode
    file << username << " " << password << endl;

    cout << "Registration successful!\n";
}

// Function to login user
void loginUser() {
    string username, password;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    ifstream file("users.txt");
    string u, p;
    bool found = false;

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Invalid username or password. Try again.\n";
    }
}

// Main menu
int main() {
    int choice;

    cout << "---- Login and Registration System ----\n";
    cout << "1. Register\n";
    cout << "2. Login\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        registerUser();
    } else if (choice == 2) {
        loginUser();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}