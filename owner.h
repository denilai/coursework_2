#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include <vector>
#include "sructures.h"
#include "snoopes.h"

class Owner{
public:

	//-----поля для реализации функционала сигналов и обработчиков-----//
	own_connects_t connections;
	//----------------------protected signals--------------------------//
	//virtual void signal_template(std::string&);
	//----------------------protected slots----------------------------//
	//virtual void slot_template(std::string&);
	//-----------------------------------------------------------------//

	void set_connection(looper, Snoopy*, snooper, const int); // установить соеднинение
	void emit_signal(looper);						          // испустить сигнал, опопвестить обработчики
	void delete_connection(const int);                            // разорвать связь
	neighbors* loop_survey();											// опрос обработчиков на текущей итерации

	explicit Owner(const int dim=0);
	void create_field(std::istream*);// метод задания поля
	void show_matrix()const;// метод вывода поля
	neighbors take_neigh(position) const;// использовать catch{}, метод передает структуру соседей
	bool get_el(position) const;// метод возвращает элемент по позиции 
	void find_first_unit();
	friend void process(std::istream*, Owner*);
private:
	const int dim;// размерность поля
	std::vector<std::vector<char>> field;// поле
	position current_unit;// координата последней найденной единицы
};

#endif
