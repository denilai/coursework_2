#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include "sructures.h"

class Owner {

private:
	std::vector<std::string> field;								// поле
	position current_unit;										// координата последней найденной единицы
public:
	to_snp_pair_t connections;

	void set_connection(looper, pack, snoopers, const int);		// установить соеднинение
	bool emit_signal(looper);									// испустить сигнал, опопвестить обработчики
	void delete_connection(const int);							// разорвать связь
	neighbors loop_survey();									// опрос обработчиков на текущей итерации
	bool step(std::string);
	explicit Owner(const int dim = 0);
	Owner(const Owner* old);
	char& operator[](position);
	friend char& operator%(Owner*, position);
	position get_curr_unit();
	void create_field(std::istream&);							// метод задания поля
	void show_matrix()const;									// метод вывода поля
	neighbors take_neighbors(position) const;					// использовать catch{}, метод передает структуру соседей
	void find_first_unit();
	friend void process(Owner*);

};

#endif
