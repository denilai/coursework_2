#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include "sructures.h"


class Owner {
public:


	to_snp_pair_t connections;

	void set_connection(looper, pack, snoopers, const int);		// установить соеднинение
	bool emit_signal(looper);							// испустить сигнал, опопвестить обработчики
	void delete_connection(const int);							// разорвать связь
	neighbors* loop_survey();									// опрос обработчиков на текущей итерации
	bool step(std::string);
	explicit Owner(const int dim = 0);
	Owner(Owner* old);
	void create_field(std::istream*);							// метод задания поля
	void show_matrix()const;									// метод вывода поля
	neighbors take_neighbors(position) const;						// использовать catch{}, метод передает структуру соседей
	//bool get_el(position) const;								// метод возвращает элемент по позиции 
	void find_first_unit();
	friend void process(std::istream*, Owner*);
private:
	const int dim;												// размерность поля
	std::vector<std::vector<char>> field;						// поле
	position current_unit;										// координата последней найденной единицы
};

#endif
