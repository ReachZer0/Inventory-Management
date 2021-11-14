#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include<stdio.h>
#include "User.cpp"
#include "FileUtil.cpp"
using namespace std;
const char USER[] = "Users.dat";
class UserService {
private:
	User user;
	string username;
	FileUtil fileUtil;
public:
	bool breakout = false;
	int choice = 0;

	void displayMenu() {
		cout << "\t\t\t\t\t1. Add User" << endl;
		cout << "\t\t\t\t\t2. View User" << endl;
		cout << "\t\t\t\t\t3. Update User" << endl;
		cout << "\t\t\t\t\t4. Delete User" << endl;
		cout << "\t\t\t\t\t5. Exit" << endl;
		cout << "\t\t\t\t\tPlease select your option (1-4): ";
		cin >> choice;

		switch (choice) {
			case 1: {
				system("cls");
				user.getUser(2);
				addUser(user);
				break;
			}
			case 2: {
				system("cls");
				viewUser();
				system("pause");
				break;
			}
			case 3: {
				system("cls");
				viewUser();
				cout << "Enter username to update: ";
				cin >> username;
				system("cls");
				updateUser(username);
				break;
			}
			case 4: {
				system("cls");
				viewUser();
				cout << "Enter username to delete: ";
				cin >> username;
				deleteUser(username);
				break;
			}
			case 5: {
				system("cls");
				breakout = true;
				break;
			}
		}

	}

	void addUser(User& user) {
		ofstream fout;
		fout.open(USER, ios::out | ios::app | ios::binary);
		if (!fout) {
			cerr << "FILE IS FAIL TO OPEN";
			exit(1);
		}
		fout.write((char*)&user, sizeof(User));
		fout.close();
	}

	void viewUser() {
		User user;
		ifstream fin;
		fin.open(USER, ios::in | ios::binary);
		while (fin.read((char*)&user, sizeof(User))) {
			if (fin.eof()) {
				break;
			}
			user.displayUser();
		}
		fin.close();
	} 

	void updateUser(string username) {
		fstream fio;
		fio.open(USER, ios::in | ios::out | ios::binary);
		if (!fio) {
			cerr << "File open failed";
			exit(1);
		}

		while (fio.read((char*)&user, sizeof(User))) {
			if (user.getUsername() == username) {
				user.getUser(2);
				int position = (-1) * static_cast<int>(sizeof(User));
				fio.seekp(position, ios::cur);
				fio.write((char*)&user, sizeof(User));
				cout << "User updated" << endl;
				break;
			}
		}
		fio.close();
	}

	void deleteUser(string username) {
		
		ifstream fin;
		ofstream fout;

		fin.open(USER, ios::in | ios::binary);
		if (!fout) {
			cerr << "FILE IS FAIL TO OPEN";
			exit(1);
		}
		fout.open("temp.dat", ios::out | ios::app | ios::binary);
		fin.seekg(0, ios::beg);
		while (fin.read((char*)&user, sizeof(User))) {
			if (user.getUsername() != username) {
				fout.write((char*)&user, sizeof(User));
			}
		}
		fin.close();
		fout.close();
		if (remove("user.dat") != 0)
		{
			cout << "Failed to remove!" << endl;
		}
		rename("temp.dat", "Users.dat");
		cout << "User has been delete" << endl;
	}

};