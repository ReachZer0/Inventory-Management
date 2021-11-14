#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Items.cpp"
using namespace std;
const char ITEMS[] = "Items.dat";
class InventoryService {
private:
	Items items;
	int choice = 0;
	string name;
public:
	bool breakout = false;

	void displayMenu() {
		cout << "\t\t\t\t\t\t~1. Add Item" << endl;
		cout << "\t\t\t\t\t\t~2. Display All Items" << endl;
		cout << "\t\t\t\t\t\t~3. Update Items" << endl;
		cout << "\t\t\t\t\t\t~4. Remove Items" << endl;
		cout << "\t\t\t\t\t\t~0. Exit" << endl;
		cout << "\t\t\t\t\t\tPlease select your option (1-4): ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1:
			system("cls");
			items.getItem();
			addItems(items);
			break;
		case 2:
			system("cls");
			displayItems();
			system("pause");
			break;
		case 3:
			system("cls");
			displayItems();
			cout << "Enter items to update: ";
			cin >>	name;
			updateItems(name);
			break;
		case 4:
			system("cls");
			displayItems();
			cout << "Enter item name to delete: ";
			cin >> name;
			deleteUser (name);
			break;
		case 5:
			system("cls");
			breakout = true;
			break;
		}
	}

	void addItems(Items& items) {
		ofstream fout;
		fout.open(ITEMS, ios::out | ios::app | ios::binary);
		if (!fout) {
			cerr << "FILE IS FAIL TO OPEN";
			exit(1);
		}
		fout.write((char*)&items, sizeof(Items));
		fout.close();
	}

	void displayItems() {
		Items items;
		ifstream fin;
		fin.open(ITEMS, ios::in | ios::binary);
		while (fin.read((char*)&items, sizeof(Items))) {
			if (fin.eof()) {
				break;
			}
			items.displayItems();
		}
		fin.close();
	}

	void updateItems(string name) {
		fstream fio;
		fio.open(ITEMS, ios::in | ios::out | ios::binary);
		if (!fio) {
			cerr << "File open failed";
			exit(1);
		}

		while (fio.read((char*)&items, sizeof(Items))) {
			if (items.getName() == name) {
				items.getItem();
				int position = (-1) * static_cast<int>(sizeof(Items));
				fio.seekp(position, ios::cur);
				fio.write((char*)&items, sizeof(Items));
				cout << "Item updated" << endl;
				break;
			}
		}
		fio.close();
	}

	void deleteUser(string name) {
		Items items;
		ifstream fin;
		ofstream fout;

		fin.open(ITEMS, ios::in | ios::binary);
		if (!fout) {
			cerr << "FILE IS FAIL TO OPEN";
			exit(1);
		}

		fout.open("temp.dat", ios::out | ios::app | ios::binary);
		fin.seekg(0, ios::beg);
		while (fin.read((char*)&items, sizeof(Items))) {
			if (items.getName() != name) {
				fout.write((char*)&items, sizeof(Items));
			}
		}
		fin.close();
		fout.close();
		if (remove("Items.dat") != 0)
		{
			cout << "Failed to remove!" << endl;
		}
		rename("temp.dat", "Items.dat");
		cout << "Item has been delete" << endl;
	}
};