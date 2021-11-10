#pragma once
#include <iostream>
#include <string>
using namespace std;

class User {
private:
	//string username, password, role;
	char username[20];
	char password[20];
	char role[20];

public:
	User() :username("Unknown"), password("unknown"), role("unknown") {}
	//User(string username, string password, string role) :username(username), password(password), role(role) {}
	User(char username[],char password[],char role[])
	{
		memcpy(this->username, username, 20);
		memcpy(this->password, password, 20);
		memcpy(this->role, role, 20);
	}
	//setter and getter
	string getUsername() const {
		return username;
	}
	/*void setUsername(string username) {
		this->username = username;
	}*/
	string getPassword() const {
		return password;
	}
	/*void setPassword(string password) {
		this->password = password;
	}*/
	string getRole() const {
		return role;
	}
	/*void setRole(string role) {
		this->role = role;
	}*/

	void getUser(int role) { //roel ==1 admin ,role == 2 user
		cout << "\t\t\t\t\t\tPlease enter your username: ";
		cin >> username;
		cout << "\t\t\t\t\t\tPlease enter your password: ";
		cin >> password;
		/*cout << "\t\t\t\t\t\tPlease enter your role: ";
		cin >> role;*/
		if (role == 1) {
			memcpy(this->role, "admin", 6);
		}
		if (role == 2) {
			memcpy(this->role, "user", 5);
		}
	}

	void displayUser() {
		cout << "\t\t\t\t\t\t---------- DISPLAY INFORMATION ----------\n";
		cout << "\t\t\t\t\t\tName : " << username << endl;
		cout << "\t\t\t\t\t\tPassword : " << password << endl;
		cout << "\t\t\t\t\t\tRole : " << role << endl;
	}


};