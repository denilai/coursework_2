#ifndef STRUCTURES
#define STRUCTURES
#include <queue>

typedef struct {// структура, предстваляющая
				// элемент массива как двумерную структуру (координаты)
				// по сути просто std::pair
	int row;
	int col;
}position;

typedef struct {// соседи какого-либо элемента массива. 
	bool top = false;
	bool right = false;
	bool bot = false;;
	bool left = false;
}neighbours;


class Owner;
class Snoopy;

typedef void (Owner::* sig_ptr_t)(std::string&);// указатели на методы Owner
typedef void (Snoopy::* slt_ptr_t)(std::string&);// указатели на методы Snoopy

typedef  struct {// Структура, отражающая всю информацию о сигнале
	Snoopy* handler;// обработчик
	slt_ptr_t slot;// метод обработчика
	int sig_num;// идентификатор сигнала
}sig_info_t;

typedef  struct {
	int sig_num;
	Owner* transmitter;
	Snoopy* handler;
	sig_ptr_t signal;
}input_form_t;// форма, аналогичная форме задания связей

typedef  struct {
	Owner* transmitter;
	sig_ptr_t signal;
}emit_struct_t; // структура для вызова метода emit_signal


typedef std::pair<sig_ptr_t, sig_info_t*> transm_info_t;// полная информация о связи сигнал-обработчик

typedef std::vector<transm_info_t> connects_t;// разъемы 
typedef std::vector<emit_struct_t> unique_callers_vec_t; // список уникальных объектов-передатчиков и их связных праметров
typedef std::queue<input_form_t> link_queue_t;// очередь объявления связей 

#endif
