#include <iostream>
#include <fstream>
#include "FileNotFoundException.cpp"
#include "User.cpp"
using namespace std;
class FileUtil {
private:
	ofstream fout;
	User user;
public:

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
};