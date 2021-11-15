#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
private:
	char username[20];
	char password[20];
	char role[20];

public:
	User() :username("Unknown"), password("unknown"), role("unknown") {
	}
	User(char username[],char password[],char role[])
	{
		memcpy(this->username, username, 20);
		memcpy(this->password, password, 20);
		memcpy(this->role, role, 20);
	}

	string getUsername() const {
		return username;
	}

	string getPassword() const {
		return password;
	}

	string getRole() const {
		return role;
	}

	void getUser(int role) { //role ==1 admin ,role == 2 user
		cout << "\t\t\t\t\t\tPlease enter your username: ";
		cin >> username;
		cout << "\t\t\t\t\t\tPlease enter your password: ";
		cin >> password;

		if (role == 1) {
			memcpy(this->role, "admin", 6);
		}
		if (role == 2) {
			memcpy(this->role, "user", 5);
		}
	}

	void displayUser() {
		cout << "\t\t\t\t\tName : " << username << " \t";
		cout << "Password : " << password << " ";
		cout << "Role : " << role << "\n\n";
	}


};