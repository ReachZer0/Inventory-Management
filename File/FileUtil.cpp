#pragma once
#include <iostream>
#include <fstream>
#include "../FileException/FileNotFoundException.cpp"
#include "../UserService/User.cpp"
#include "../ItemsService/Items.cpp"
using namespace std;
class FileUtil {
private:
	ofstream fout;
	ifstream fin;
	User user;
	Items items;
public:

	void OpenDataToFile(string filename)
	{
		fout.open(filename, ios::out | ios::app | ios::binary);
		if (!fout)
		{
			cerr << "FILE IS FAIL TO OPEN!" << endl;
			system("pause");
		}
	}

	void openUserOutputFile(string filename) {
		try {
			fout.open(filename, ios::out | ios::app | ios::binary);
		}
		catch (FileNotFoundException& e) {
			cerr << e.what() << endl;
		}
	}

	void writeUserDataToFile(User user) {
		fout.write((char*)&user, sizeof(User));
	}

	void writeItemsDataToFile(Items items) {
		fout.write((char*)&items, sizeof(Items));
	}

	void closeUserOutputFile() {
		fout.close();
	}

	ifstream openUserInputFile(string filename) {
		ifstream fin;
		try {
			fin.open(filename, ios::in, ios::binary);
		}
		catch (FileNotFoundException& e) {
			cerr << e.what() << endl;
		}
		return fin;
	}

	void closeUserInputFile() {
		fin.close();
	}

};