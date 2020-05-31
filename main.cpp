#include "snoopes.h"
#include "owner.h"
#include "functions.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;

int main() {
	std::istream* stream = selector("Statdart console input (cin)\t|1", "Input from file\t\t\t|2");
	Owner field(4);
	field.create_field(stream);
	field.find_first_unit();
	process(stream, &field);
	system("pause");
	return 0;
}