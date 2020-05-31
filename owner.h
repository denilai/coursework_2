#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include <vector>
#include "sructures.h"
#include "snoopes.h"

class Owner{
public:

	//-----поля для реализации функционала сигналов и обработчиков-----//
	connects_t connections;
	//----------------------protected signals--------------------------//
	//virtual void signal_template(std::string&);
	//----------------------protected slots----------------------------//
	//virtual void slot_template(std::string&);
	//-----------------------------------------------------------------//

	//void set_connection(sig_ptr_t, Snoopy*, slt_ptr_t, const int);// установить соеднинение
	//void emit_signal(sig_ptr_t, std::string&);                    // испустить сигнал, опопвестить обработчики
	void delete_connection(const int);                            // разорвать связь

	explicit Owner(const int dim=0);
	void create_field(std::istream*);// метод задания поля
	void show_matrix()const;// метод вывода поля
	neighbours take_3x3(position) const;// использовать catch{}, метод передает структуру соседей
	bool get_el(position) const;// метод возвращает элемент по позиции 
	void find_first_unit();
	friend void process(std::istream*, Owner*);
private:
	const int dim;// размерность поля
	std::vector<std::vector<char>> field;// поле
	position current_unit;// координата последней найденной единицы
};

#endif
