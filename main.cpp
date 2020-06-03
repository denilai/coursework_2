#include "snoopes.h"
#include "owner.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

inline std::string switcher() {
	int res = 0;
	std::string Name;
	cout << "Select file:\n1)Test1.txt\n2)Test2.txt\n3)Test3.txt\n4)Test4.txt\n5)Test5.txt\n6)Test6.txt\n7)Test7.txt\n8?Test8.txt\n" << endl;
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
	case 7: Name = "Test7.txt";
		break;
	case 8: Name = "Test8.txt";
		break;
	case 9: Name = "Test9.txt";
		break;
	}
	return Name;
}

template<class ONE,class TWO>
ONE& selector(ONE& first, TWO& second, const string first_line, const string second_line) {
	int answer;
	cout << "\n\nChoose one option:" << endl;
	cout << "-------------------" << endl;
	cout << first_line << endl;
	cout << second_line << endl;
	cout << ">";
	cin >> answer;
	cout << "\n";
	if (!(answer == 1 || answer == 2))
		return selector(first, second, first_line, second_line);
	if (answer == 2)
		dynamic_cast<std::ifstream&>(second).std::ifstream::open(switcher());
	return (answer == 1) ? first : dynamic_cast<std::ifstream&>(second);
}




int main() {
	//system("README.txt");
	//std::ifstream file(switcher());
	std::ifstream file;
	std::string line;
	//file>> line;
	std::istream& stream = selector(cin, file, "Statdart console input (cin)  1", "Input from file           2");
	int a = 10;
	Owner field(a);
	/*TopSnoopy Top;
	RightSnoopy Right;
	BotSnoopy Bot;
	LeftSnoopy Left;*/
	field.create_field(stream);
	process(&field);
	system("pause");
	return 0;
}