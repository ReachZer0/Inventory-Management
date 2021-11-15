#pragma once
#include <iostream>
#include "../UserService/User.cpp"

using namespace std;
class FileNotFoundException:public exception {
public:
	virtual const char* what() const throw() {
		return "File Not Found.";
	}
};
