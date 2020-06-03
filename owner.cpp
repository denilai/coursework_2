#include <iostream>
#include <vector>
#include "owner.h"
#include "snoopes.h"
#include <algorithm>

Owner::Owner(int dim) :current_unit({ -1,-1 }) {
	field.resize(dim);
}

Owner::Owner(const Owner* old) : current_unit(old->current_unit), field(old->field) {}


void Owner::find_first_unit() {
	int first, last;
	std::vector<char> null_col;
	for (auto& line : field)
		null_col.push_back(line[0]);
	if (find(null_col.begin(),null_col.end(),'1')==null_col.end())
		return;
	for (auto& elem : null_col) 
		if (elem == '1') {
			first = &elem - &null_col.front();
			break;
		}
	reverse(null_col.begin(),null_col.end());
	for (auto& elem : null_col)
		if (elem == '1') {
			last = &null_col.back() - &elem;
			break;
		}
	if (last == first) {
		current_unit = {last,0 };
		return;
	}
	neighbors f= take_neighbors({ first, 0 });
	neighbors l = take_neighbors({ last, 0 });
	if(!f.right)
		current_unit = { first,0 };
	if(!l.right)
		current_unit = { last,0 };
}

position Owner::get_curr_unit()
{
	this->find_first_unit();
	return current_unit;
}

void Owner::create_field(std::istream& stream) {
	std::string line;
	for (int i = 0; i < field.size(); i++) {
		stream >> line;
		field[i]=line;
	}
}

void Owner::show_matrix() const {
	for (auto &vec : field) {
		if (&vec != &field.front())
			std::cout << std::endl;
		for (auto el : vec)
			std::cout << el;
	}
}



neighbors Owner::loop_survey()
{
	try {
		return take_neighbors(current_unit);
	}
	catch (int) {
		return { false,false,false,false };
	}
}

 bool Owner::step(std::string message) {
	if (current_unit.col < 0 || current_unit.row < 0) {
		return false;
	}
	if (message[message.length() - 1] == '2')
		 return 0;
	try {
		this% current_unit = 'F';
	}
	catch (...) {};
	switch (message[0])
	{
	case't':
		current_unit.row--;
		break;
	case'r':
		current_unit.col++;
		break;
	case'b':
		current_unit.row++;
		break;
	case'l':
		current_unit.col--;
		break;
	default:
		return 0;
	}
	return 1;
}



neighbors Owner::take_neighbors(position elem)const {
	neighbors symb;
	Owner temp = (this);
	size_t const dim = field.size();
	position left = { elem.row,elem.col - 1 },
			right= { elem.row,elem.col + 1 },
			top= { elem.row - 1 ,elem.col },
			bot= { elem.row + 1,elem.col };
	if (elem.row < 0 || elem.col < 0)
		throw 1;
	if (elem.row >= dim || elem.col >= dim)
		throw 2;
	try {symb.top = temp[top] == '1' ? true : false;}
	catch (char) {}
	try {symb.bot = temp[bot] == '1' ? true : false;}
	catch (char) {}
	try {symb.left = temp[left] == '1' ? true : false;}
	catch (char) {}
	try {symb.right = temp[right] == '1' ? true : false;}
	catch (char) {}
	return symb;
}


//----------------------- сигналы-обработчики--------------------------------------------
void Owner::set_connection(looper signal, pack handlers, snoopers slots, const int sig_num) {
	if (connections.second.sig_num == sig_num)
		return;
	to_snp_info_t  din_struct;
	din_struct.handlers = handlers;
	din_struct.slots = slots;
	din_struct.sig_num = sig_num;
	connections = (std::make_pair(signal, din_struct));
	return;
}

void Owner::delete_connection(const int sig_num) {
	connections.first = nullptr;
	connections = { nullptr ,{0,0} };
};


bool Owner::emit_signal(looper signal) {
	bool flag = false;
	std::vector<bool> flags;
	if (connections.first != signal)
		return 0;
	neighbors neighbors = (this->*signal)();
	if (neighbors.top) {
		flags.push_back((connections.second.handlers.top->*connections.second.slots.tsnp)(neighbors));
		neighbors = (this->*signal)();
	}
	else if (neighbors.right) {
		flags.push_back((connections.second.handlers.right->*connections.second.slots.rsnp)(neighbors));
		neighbors = (this->*signal)();
	}
	else {
		flags.push_back((connections.second.handlers.bot->*connections.second.slots.bsnp)(neighbors));
		neighbors = (this->*signal)();
	}
	for (auto const& flag : flags)
		if (flag)
			return 1;
	try {
		this% current_unit = 'F';
	}
	catch (...) {};
	return 0;
}

//----------------------------перегрузка оператора------------------------------------

char& Owner::operator[](position pos) {
	if (pos.col < 0 || pos.row < 0)
		throw 'a';
	if (pos.col >= field.size() || pos.row >= field.size())
		throw 'b';
	return this->field[pos.row][pos.col];
}