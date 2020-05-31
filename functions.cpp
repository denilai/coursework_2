#include <iostream>
#include <fstream>
#include <string>
#include"functions.h"

using std::cin;
using std::cout;
using std::endl;

std::string switcher() {
	int res = 0;
	std::string Name;
	cout << "Select file:\n1)Test1.txt\n2)Test2.txt\n3)Test3.txt\n4)Test4.txt\n5)Test5.txt\n6)Test6.txt\n" << endl;
	cin >> res;
	switch (res) {
	case 1: Name = "Test1.txt";
		break;
	case 2: Name = "Test2.txt";
		break;
	case 3: Name = "Test3.txt";
		break;
	case 4: Name = "Test4.txt";
		break;
	case 5: Name = "Test5.txt";
		break;
	case 6: Name = "Test6.txt";
		break;
	}
	return Name;
}

std::istream* selector(const std::string first_line, const std::string second_line) {
	std::string Name;
	int answer = 0;
	cout << "\nChoose one option:" << endl;
	cout << "-------------------" << endl;
	cout << first_line << endl;
	cout << second_line << endl;
	cout << ">";
	cin >> answer;
	if (cin.fail()) {
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		return selector(first_line, second_line);
	}
	cout << "\n";
	if (!(answer == 1 || answer == 2))
		return selector(first_line, second_line);
	if (answer == 2) {
		Name = switcher();
		std::ifstream file(Name);
		if (!file.good()) {
			cout << "ERROR File " << Name << " can't be opend" << endl;
			return selector(first_line, second_line);
		}
		return &file;
	}
	return &cin;
}