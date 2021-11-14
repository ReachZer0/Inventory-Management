#include <iostream>
#include "User.cpp"

using namespace std;
class FileNotFoundException:public exception {
public:
	virtual const char* what() const throw() {
		return "File Not Found.";
	}
};
