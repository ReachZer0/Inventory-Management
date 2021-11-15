#pragma once
#include <iostream>
#include "../Inventory Management/UserService/User.cpp"
#include "../Inventory Management/UserService/UserService.cpp"
#include "../Inventory Management/ItemsService/InventoryService.cpp"
#include "../Inventory Management/Authentication/UserAuthentication.cpp"
using namespace std;

class App {
private:
    int choice = 0;
    void displayMainMenu() {
        cout << "\t\t\t\t\t==========--MANAGEMENT SYSTEM--==========" << endl;
        cout << "\t\t\t\t\t~1. Login" << endl;
        cout << "\t\t\t\t\t~2. Create New User" << endl;
        cout << "\t\t\t\t\t~3. Exit" << endl;
        cout << "\t\t\t\t\t~Please select your option (1-3):";
        cin >> choice;
    }

    char username[20], password[20], role[10];
    UserService userService;
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
                user.getUser(2); //1 for admin, 2 for user
                userService.addUser(user);
                break;

            }
        } while (choice != 3);

	}

};
