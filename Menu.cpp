#pragma once
#include <iostream>
#include <fstream>
#include "User.cpp"
#include "InventoryService.cpp"
#include "UserService.cpp"
using namespace std;

class UserMenu {
private:
public:

	void showAdminMenu() {
		int selectchoice = 0;
		bool breakout = false;
		do {
			system("cls");
			cout << "\t\t\t\t\t==========--ADMIN MENU--==========" << endl;
			cout << "\t\t\t\t\t1. User Management" << endl;
			cout << "\t\t\t\t\t2. Inventory Mangement" << endl;
			cout << "\t\t\t\t\t3. Exit" << endl;
			cout << "\t\t\t\t\tPlease select your option (1-3): ";
			cin >> selectchoice;

			switch (selectchoice) {
			case 1: {
				system("cls");
				cout << "\t\t\t\t\t==========--USER MANAGEMENT MENU--==========" << endl;
				UserService userService;
				userService.displayMenu();
				break;
			}
			case 2: {
				system("cls");
				cout << "\t\t\t\t\t==========--INVENTORY MANAGEMENT MENU--==========" << endl;
				InventoryService inventoryService;
				inventoryService.displayMenu();
				break;
			}
			case 3: {
				breakout = true;
				break;
			}

			}

		} while (breakout == false);


	}

	void showUserMenu() {
		int selectchoice = 0;
		bool breakout = false;
		do {
			system("cls");
			cout << "\t\t\t\t\t==========--USER MENU--==========" << endl;
			cout << "\t\t\t\t\t1. Inventory Mangement" << endl;
			cout << "\t\t\t\t\t2. Exit" << endl;
			cout << "\t\t\t\t\tPlease select your option (1-2): ";
			cin >> selectchoice;

			switch (selectchoice) {
				case 1: {
					system("cls");
					cout << "\t\t\t\t\t==========--INVENTORY MENU--==========" << endl;
					InventoryService inventoryService;
					inventoryService.displayMenu();
					break;
				}
				case 2: {
					breakout = true;
					break;
				}
			}

		} while (breakout == false);
	}
};