#pragma once
#include <iostream>
#include <string>
using namespace std;

class Items {
private:
	char name[20];
	char brand[20];
	float quantity;
	float price;
public:
	Items() :name("Unknown"), brand("unknown"), quantity('0'), price('0') {}
	Items(char name[], char brand[], float quantity, float price)
	{
		memcpy(this->name, name, 20);
		memcpy(this->brand, brand, 20);
		this->quantity = quantity;
		this->price = price;
	}

	//setter and getter
	string getName() const {
		return name;
	}
	/*void setName(string name) {
		this->name = name;
	}*/

	string getBrand() const {
		return brand;
	}
	/*void setBrand(string brand) {
		this->brand = brand;
	}*/

	double getquantity() const {
		return quantity;
	}
	void setquantity(float quantity) {
		this->quantity = quantity;
	}

	double getPrice() const {	
		return price;
	}
	void setPrice(float price) {
		this->price = price;
	}

	void getItem() {
		cout << "\t\t\t\t\t\tEnter Item Name: ";
		cin >> name;
		cout << "\t\t\t\t\t\tEnter Manufactor/Brand name: ";
		cin >> brand;
		cout << "\t\t\t\t\t\tEnter quantity: ";
		cin >> quantity;
		cout << "\t\t\t\t\t\tEnter price: ";
		cin >> price;
	}

	void displayItems() {
		cout << "\t\t\t\t\t\tItem : " << name << endl;
		cout << "\t\t\t\t\t\tBrand/Manufactor : " << brand << endl;
		cout << "\t\t\t\t\t\tQuantity: " << quantity << endl;
		cout << "\t\t\t\t\t\tPrice: " << price << endl;
		cout << "\t\t\t\t\t\t----------------------------------------" << endl;
	}
};