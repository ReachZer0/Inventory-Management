#pragma once
#include <iostream>
#include "User.cpp"
#include "UserManagement.cpp"
#include "InventoryManagement.cpp"
#include "UserAuthentication.cpp"
using namespace std;

class App {
private:
    int choice = 0;
    void displayMainMenu() {
        cout << "\t\t\t\t\t==========--MANAGEMENT SYSTEM--==========" << endl;
        cout << "\t\t\t\t\t~1. Login" << endl;
        cout << "\t\t\t\t\t~2. Create New User" << endl;
        cout << "\t\t\t\t\t~3. View User" << endl;
        cout << "\t\t\t\t\t~4. Exit" << endl;
        cout << "\t\t\t\t\t~Please select your option (1-4):";
        cin >> choice;
    }

    char username[20], password[20], role[10];
    UserManagement userManagement;
    UserAuth userAuth;
    User user;
public:

	void run(){
        do {
            system("cls");
            displayMainMenu(); 

            switch (choice) {
            case 1:
                system("cls");
                cout << "\t\t\t\t\tEnter your username: ";
                cin >> username;
                cout << "\t\t\t\t\tEnter your password: ";
                cin >> password;
                userAuth.authenticateUser(username, password);
                break;
            
            case 2:
                system("cls");
                cout << "\t\t\t\t\t\t==========---Create New User---==========\n";
                user.getUser(2);
                userManagement.addUser(user);
                break;
            case 3:
                system("cls");
                userManagement.viewUser();
                system("pause");
                break;
            }
        } while (choice != 4);

	}

};
