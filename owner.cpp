#include <iostream>
#include <vector>
#include "owner.h"
#include "snoopes.h"

Owner::Owner(const int dim) :dim(dim), current_unit({ -1,-1 }) {
	field.assign(dim, std::vector<char>(dim));
}

Owner::Owner(Owner* old) : dim(old->dim), current_unit(old->current_unit), field(old->field) {}

void Owner::find_first_unit() {
	for (int i = 0, j = 0; i < dim; i++)
		if (field[i][j] == '1') {
			current_unit = { i,j };
			return;
		}
}

void Owner::create_field(std::istream* stream) {
	std::string line;
	for (int i = 0; i < dim; i++) {
		*stream >> line;
		for (int j = 0; j < dim; j++)
			field[i][j] = line[j];
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
	if (connections.second && connections.second->sig_num == sig_num)
		return;
	to_snp_info_t* din_struct = new to_snp_info_t;
	din_struct->handlers = handlers;
	din_struct->slots = &slots;
	din_struct->sig_num = sig_num;
	connections=(std::make_pair(signal, din_struct));
	return;
}

void Owner::delete_connection(const int sig_num) {
	connections.first = nullptr;
	connections = { nullptr ,nullptr };
};

bool Owner::emit_signal(looper signal) {
	bool flag = false;
	std::vector<std::string> answers;
	neighbors* neighbors = (this->*signal)();
	
	if (connections.first != signal)
		return 0;
	std::cout << std::endl << "Signal to " << connections.second->handlers.bot->get_name();
	std::cout << " neighbors:\n";
	std::cout << '\t' << neighbors->top << std::endl;
	std::cout << neighbors->left << '\t' << std::endl;
	std::cout << neighbors->right << std::endl;
	std::cout << '\t' << neighbors->bot << std::endl;
			
	answers.push_back((connections.second->handlers.top->*connections.second->slots->tsnp)(neighbors));
	answers.push_back((connections.second->handlers.right->*connections.second->slots->rsnp)(neighbors));
	answers.push_back((connections.second->handlers.bot->*connections.second->slots->bsnp)(neighbors));
	answers.push_back((connections.second->handlers.left->*connections.second->slots->lsnp)(neighbors));
	for (auto const& line : answers)
		if (step(line))
			break;
	return flag;
}

neighbors* Owner::loop_survey()
{
	return &take_neighbors(current_unit);
}

 bool Owner::step(std::string message) {
	field[current_unit.row][current_unit.col] = 'F';
	if (message[message.length() - 1] == '2')
		 return 0;
	switch (message[0])
	{
	case't':
		current_unit.row++;
		break;
	case'r':
		current_unit.col++;
		break;
	case'b':
		current_unit.row--;
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

neighbors Owner::take_neighbors(position elem)const {
	neighbors symb;
	if (elem.row < 0 || elem.col < 0)
		exit(1);
	if (elem.row >= dim || elem.col >= dim)
		exit(2);
	if (elem.row % (dim - 1) == 0 && elem.col % (dim - 1) == 0) {//рассматриваем уловые элементы
		if (elem.row == elem.col == 0) {// рассматриваем верхний левый угол
			symb.right = field[0][1] == '1' ? true : false;
			symb.bot = field[1][0] == '1' ? true : false;
			return symb;
		}
		if (elem.row == 0 && elem.col == dim - 1) {// рассматриваем верхний правый угол
			symb.left = field[0][dim - 2] == '1' ? true : false;
			symb.bot = field[1][dim - 1] == '1' ? true : false;
			return symb;
		}
		if (elem.row == dim - 1 && elem.col == 0) {// рассматриваем нижний левый угол
			symb.top = field[dim - 2][0] == '1' ? true : false;
			symb.right = field[dim - 1][1] == '1' ? true : false;
			return symb;
		}
		if (elem.row == elem.col == dim - 1) {// рассматриваем нижний правый угол
			symb.top = field[dim - 2][dim - 1] == '1' ? true : false;
			symb.left = field[dim - 1][dim - 2] == '1' ? true : false;
			return symb;
		}
	}
	if (elem.row == 0) {// рассматриваем первую строку (без углов)
		symb.left = field[elem.col][elem.col - 1] == '1' ? true : false;
		symb.right = field[elem.col][elem.col + 1] == '1' ? true : false;
		symb.bot = field[elem.col + 1][elem.col] == '1' ? true : false;
		return symb;
	}
	if (elem.row == dim - 1) {// рассматриваем последнюю строку (без углов)
		symb.left = field[elem.row][elem.col - 1] == '1' ? true : false;
		symb.right = field[elem.row][elem.col + 1] == '1' ? true : false;
		symb.top = field[elem.row - 1][elem.col] == '1' ? true : false;
		return symb;
	}
	if (elem.col == 0) {// рассматриваем левую строку (без углов)
		symb.bot = field[elem.row + 1][elem.col] == '1' ? true : false;
		symb.right = field[elem.row][elem.col + 1] == '1' ? true : false;
		symb.top = field[elem.row - 1][elem.col] == '1' ? true : false;
		return symb;
	}
	if (elem.col == dim - 1) {// рассматриваем правую строку (без углов)
		symb.bot = field[elem.row + 1][elem.col] == '1' ? true : false;
		symb.left = field[elem.row][elem.col - 1] == '1' ? true : false;
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

void process(std::istream*, Owner* matrix) {
	looper loop = &Owner::loop_survey;

	tsnooper top = &TopSnoopy::IsUnitHere;
	rsnooper right = &RightSnoopy::IsUnitHere;
	bsnooper bot = &BotSnoopy::IsUnitHere;
	lsnooper left = &LeftSnoopy::IsUnitHere;
	snoopers slots = { top,right,bot,left };

	TopSnoopy* Top = new TopSnoopy;
	RightSnoopy* Right = new RightSnoopy;
	BotSnoopy* Bot = new BotSnoopy;
	LeftSnoopy* Left = new LeftSnoopy;
	pack headers = { Top,Right,Bot,Left };

	matrix->set_connection(loop, headers, slots, 1);
	/*Top->set_connection(matrix)
	for (;;) {
		if()
	}*/
}

