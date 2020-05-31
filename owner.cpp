#include "owner.h"
#include <iostream>
#include <string>

Owner::Owner(const int dim) :dim(dim), current_unit({-1,-1}) {
	field.assign(dim, std::vector<char>(dim));
}

void Owner::find_first_unit() {
	for (int i=0, j = 0; i< dim; i++)
		if (field[i][j] == '1') {
			current_unit = { i,j };
			return;
		}
}

void Owner::create_field(std::istream*stream) {
	std::string line;
	for (int i = 0; i < dim; i++) {
		*stream >> line;
		for (int j = 0; j < dim; j++)
			field[i][j] = line[j];
	}
}

void Owner::show_matrix() const{
	for (auto vec : field) {
		for (auto el : vec)
			std::cout << el;
		std::cout << std::endl;
	}
}

bool Owner::get_el(position elem)const {
	return field[elem.row][elem.col] == '1' ? true : false;
}

//----------------------- сигналы-обработчики--------------------------------------------
void Owner::set_connection(looper signal, Snoopy* handler, snooper slot, const int sig_num) {
	for (auto it = connections.begin(); it != connections.end(); it++)
		if (it->second->sig_num == sig_num)
			return;
	to_snp_info_t* din_struct = new to_snp_info_t;
	din_struct->handler = handler;
	din_struct->slot = slot;
	din_struct->sig_num = sig_num;
	connections.push_back(std::make_pair(signal, din_struct));
	return;
}

void Owner::delete_connection(const int sig_num) {
	for (auto it = connections.begin(); it != connections.end(); it++)
		if (it->second->sig_num == sig_num) {
			connections.erase(it);
			return;
		}
}

void Owner::emit_signal(looper signal) {
	neighbors *neighbors=(this->*signal)();
	for (auto const& connection : connections) {
		if (connection.first == signal) {
			std::cout << std::endl << "Signal to " << connection.second->handler->get_name();
			std::cout << " neighbors:\n";
			std::cout << '\t'<<neighbors->top << std::endl;
			std::cout << neighbors->left << '\t' << std::endl;
			std::cout << neighbors->right << std::endl;
			std::cout << '\t' << neighbors->bot << std::endl;
			(connection.second->handler->*connection.second->slot)(neighbors);
		}
	}
}

neighbors* Owner::loop_survey()
{
	return &take_neigh(current_unit);
}

//------------------------------------------------------------------------------------

neighbors Owner::take_neigh(position elem)const {
	neighbors symb;
	if (elem.row < 0 || elem.col < 0)
		exit(1);
	if (elem.row >= dim || elem.col >= dim)
		exit(2);
	if (elem.row % (dim - 1) == 0 && elem.col % (dim - 1) == 0){//рассматриваем уловые элементы
		if (elem.row == elem.col == 0) {// рассматриваем верхний левый угол
			symb.right = field[0][1]=='1'?true:false;
			symb.bot = field[1][0]=='1'?true:false;
			return symb;
		}
		if (elem.row == 0 && elem.col == dim - 1) {// рассматриваем верхний правый угол
			symb.left = field[0][dim - 2] == '1' ? true : false;
			symb.bot = field[1][dim - 1] == '1' ? true : false;
			return symb;
		}
		if (elem.row == dim-1 && elem.col == 0) {// рассматриваем нижний левый угол
			symb.top = field[dim-2][0] == '1' ? true : false;
			symb.right = field[dim-1][1] == '1' ? true : false;
			return symb;
		}
		if (elem.row == elem.col == dim - 1) {// рассматриваем нижний правый угол
			symb.top = field[dim - 2][dim-1] == '1' ? true : false;
			symb.left = field[dim - 1][dim-2] == '1' ? true : false;
			return symb;
		}
	}
	if (elem.row == 0) {// рассматриваем первую строку (без углов)
		symb.left = field[elem.col][elem.col-1] == '1' ? true : false;
		symb.right = field[elem.col][elem.col +1] == '1' ? true : false;
		symb.bot = field[elem.col+1][elem.col] == '1' ? true : false;
		return symb;
	}
	if (elem.row == dim - 1) {// рассматриваем последнюю строку (без углов)
		symb.left = field[elem.row][elem.col - 1] == '1' ? true : false;
		symb.right = field[elem.row][elem.col + 1] == '1' ? true : false;
		symb.top = field[elem.row-1][elem.col] == '1' ? true : false;
		return symb;
	}
	if (elem.col == 0) {// рассматриваем левую строку (без углов)
		symb.bot = field[elem.row+1][elem.col] == '1' ? true : false;
		symb.right = field[elem.row][elem.col+1] == '1' ? true : false;
		symb.top = field[elem.row-1][elem.col] == '1' ? true : false;
		return symb;
	}
	if (elem.col == dim-1) {// рассматриваем правую строку (без углов)
		symb.bot = field[elem.row + 1][elem.col] == '1' ? true : false;
		symb.left = field[elem.row][elem.col -1] == '1' ? true : false;
		symb.top = field[elem.row - 1][elem.col] == '1' ? true : false;
		return symb;
	}
	// случаи не в углах и не на сторонах
	symb.top = field[elem.row - 1][elem.col] == '1' ? true : false;
	symb.bot = field[elem.row + 1][elem.col] == '1' ? true : false;
	symb.left = field[elem.row][elem.col - 1] == '1' ? true : false;
	symb.right = field[elem.row][elem.col + 1] == '1' ? true : false;
	return symb;
}

void process(std::istream*, Owner* matrix){
	snooper left = &LeftSnoopy::IsUnitHere;
}
