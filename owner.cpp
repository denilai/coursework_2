#include <iostream>
#include <vector>
#include "owner.h"
#include "snoopes.h"

Owner::Owner(int dim) :current_unit({ -1,-1 }) {
	field.resize(dim);
}

Owner::Owner(const Owner* old) : current_unit(old->current_unit), field(old->field) {}


void Owner::find_first_unit() {
	for (auto &line:field)
		if (line[0] == '1') {
			current_unit = { &line - &field.front(),0};
			return;
		}
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

//----------------------- сигналы-обработчики--------------------------------------------
void Owner::set_connection(looper signal, pack handlers, snoopers slots, const int sig_num) {
	if (connections.second.sig_num == sig_num)
		return;
	to_snp_info_t  din_struct;
	din_struct.handlers = handlers;
	din_struct.slots = slots;
	din_struct.sig_num = sig_num;
	connections=(std::make_pair(signal, din_struct));
	return;
}

void Owner::delete_connection(const int sig_num) {
	connections.first = nullptr;
	connections = { nullptr ,{0,0}};
};


bool Owner::emit_signal(looper signal) {
	bool flag = false;
	std::vector<bool> flags;
	if (connections.first != signal)
		return 0;
	neighbors neighbors = (this->*signal)();
	if((connections.second.handlers.top->*connections.second.slots.tsnp)(neighbors))

	flags.push_back((connections.second.handlers.top->*connections.second.slots.tsnp)(neighbors));
	neighbors = (this->*signal)();
	flags.push_back((connections.second.handlers.right->*connections.second.slots.rsnp)(neighbors));
	neighbors = (this->*signal)();
	flags.push_back((connections.second.handlers.bot->*connections.second.slots.bsnp)(neighbors));
	neighbors = (this->*signal)();
	//flags.push_back((connections.second.handlers.left->*connections.second.slots.lsnp)(neighbors));
	//show_matrix();
	std::cout << std::endl;
	for (auto const& flag : flags)
		if (flag) {
			//field[current_unit.row][current_unit.col] = 'F';
			return 1;
		}
	try {
		this%current_unit='F';
	}
	catch(...){};
	return 0;
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

//------------------------------------------------------------------------------------

 char& Owner::operator[](position pos) {
	 if (pos.col < 0 || pos.row < 0)
		 throw 'a';
	 if (pos.col >=field.size() || pos.row>=field.size())
		 throw 'b';
	 return this->field[pos.row][pos.col];
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



