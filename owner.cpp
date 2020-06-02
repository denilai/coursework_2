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

void Owner::create_field(std::istream& stream) {
	std::string line;
	for (int i = 0; i < field.size(); i++) {
		stream >> line;
		field[i]=line;
	}
}

void Owner::show_matrix() const {
	for (auto vec : field) {
		for (auto el : vec)
			std::cout << el;
		std::cout << std::endl;
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
	neighbors neighbors = (this->*signal)();
	
	if (connections.first != signal)
		return 0;
	std::cout << std::endl << "Signal to " << connections.second.handlers.bot->get_name();
	std::cout << " neighbors:\n";
	std::cout << '\t' << neighbors.top << std::endl;
	std::cout << neighbors.left << '\t';
	std::cout << neighbors.right << std::endl;
	std::cout << '\t' << neighbors.bot << std::endl;
			
	flags.push_back((connections.second.handlers.top->*connections.second.slots.tsnp)(neighbors));
	neighbors = (this->*signal)();
	flags.push_back((connections.second.handlers.right->*connections.second.slots.rsnp)(neighbors));
	neighbors = (this->*signal)();
	flags.push_back((connections.second.handlers.bot->*connections.second.slots.bsnp)(neighbors));
	neighbors = (this->*signal)();
	flags.push_back((connections.second.handlers.left->*connections.second.slots.lsnp)(neighbors));
	neighbors = (this->*signal)();
	show_matrix();
	for (auto const& flag : flags)
		if (flag) {
			field[current_unit.row][current_unit.col] = 'F';
			return 1;
		}
	return 0;
}

neighbors Owner::loop_survey()
{
	return take_neighbors(current_unit);
}

 bool Owner::step(std::string message) {
	if (current_unit.col < 0 || current_unit.row < 0) {
		std::cout << "Out of array";
		return false;
	}
	if (message[message.length() - 1] == '2')
		 return 0;
	field[current_unit.row][current_unit.col] = 'F';
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
	 return this->field[pos.row][pos.col];
 }

neighbors Owner::take_neighbors(position elem)const {
	neighbors symb;
	Owner temp = (this);
	size_t const dim = field.size();
	position left, right, top, bot;
	left = { elem.row,elem.col - 1 };
	right = { elem.row,elem.col + 1 };
	top = { elem.row - 1 ,elem.col };
	bot = { elem.row + 1,elem.col };
	if (elem.row < 0 || elem.col < 0)
		exit(1);
	if (elem.row >= dim || elem.col >= dim)
		exit(2);
	if (elem.row % (dim - 1) == 0 && elem.col % (dim - 1) == 0) {//рассматриваем уловые элементы
		if (elem.row == elem.col == 0) {// рассматриваем верхний левый угол
			symb.right =temp[right] == '1' ? true : false;
			symb.bot = temp[bot] == '1' ? true : false;
			return symb;
		}
		if (elem.row == 0 && elem.col == dim - 1) {// рассматриваем верхний правый угол
			symb.left = temp[left] == '1' ? true : false;
			symb.bot = temp[bot] == '1' ? true : false;
			return symb;
		}
		if (elem.row == dim - 1 && elem.col == 0) {// рассматриваем нижний левый угол
			symb.top = temp[top] == '1' ? true : false;
			symb.right = temp[right] == '1' ? true : false;
			return symb;
		}
		if (elem.row == elem.col == dim - 1) {// рассматриваем нижний правый угол
			symb.top = temp[top] == '1' ? true : false;
			symb.left = temp[left] == '1' ? true : false;
			return symb;
		}
	}
	if (elem.row == 0) {// рассматриваем первую строку (без углов)
		symb.left = temp[left] == '1' ? true : false;
		symb.right = temp[right] == '1' ? true : false;
		symb.bot = temp[bot] == '1' ? true : false;
		return symb;
	}
	if (elem.row == dim - 1) {// рассматриваем последнюю строку (без углов)
		symb.left = temp[left] == '1' ? true : false;
		symb.right = temp[right] == '1' ? true : false;
		symb.top = temp[top] == '1' ? true : false;
		return symb;
	}
	if (elem.col == 0) {// рассматриваем левую строку (без углов)
		symb.bot = temp[bot] == '1' ? true : false;
		symb.right = temp[right] == '1' ? true : false;
		symb.top = temp[top] == '1' ? true : false;
		return symb;
	}
	if (elem.col == dim - 1) {// рассматриваем правую строку (без углов)
		symb.bot = temp[bot] == '1' ? true : false;
		symb.left = temp[left] == '1' ? true : false;
		symb.top = temp[top] == '1' ? true : false;
		return symb;
	}
	// случаи не в углах и не на сторонах
	symb.top = temp[top] == '1' ? true : false;
	symb.bot = temp[bot] == '1' ? true : false;
	symb.left = temp[left] == '1' ? true : false;
	symb.right = temp[right] == '1' ? true : false;
	return symb;
}



