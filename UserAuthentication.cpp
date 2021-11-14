#include <iostream>
#include <fstream>
#include "User.cpp"
#include "UserService.cpp"
#include "Menu.cpp"
using namespace std;

class UserAuth {
private:
	UserService userService;
	User user;
	UserMenu usermenu;
public:

	void authenticateUser(char username[], char password[]) {
		User user;
		ifstream fin;

		fin.open(USER, ios::in | ios::binary);
		while (fin.read((char*)&user, sizeof(User))) {
			if (user.getUsername() == username && user.getPassword() == password) {
				if (user.getRole() == "admin") {
					cout << "\t\t\t\t\tLogged in as admin:" << endl;
					fin.close();
					usermenu.showAdminMenu();
					system("pause");
					break;
				}
			}
			else {
				cout << "Invalid user." << endl;
			}
			if (user.getUsername() == username && user.getPassword() == password) {
				if (user.getUsername() == username && user.getPassword() == password) {
					if (user.getRole() == "user") {
						cout << "\t\t\t\t\tLogged in as user:" << endl;
						fin.close();
						usermenu.showUserMenu();
						system("pause");
						break;
					}
					else {
						cout << "Invalid user." << endl;
					}
				}
			}
		}

	}
};