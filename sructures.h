#ifndef STRUCTURES
#define STRUCTURES
#include <queue>
#include <string>


typedef struct {// координаты элемента по сути просто std::pair
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
class LeftSnoopy;
class RightSnoopy;
class TopSnoopy;
class BotSnoopy;

typedef std::string(Snoopy::* sig_ptr_t)(neighbours*);// указатели на методы Snoopy
typedef position (Owner::*slt_ptr_t)(neighbours);// указатели на методы Owner

//typedef std::string(Snoopy::*r_sig_t)(neighbours*);// указатели на методы Snoopy
//typedef std::string(Snoopy::*t_sig_t)(neighbours*);// указатели на методы Snoopy
//typedef std::string(Snoopy::*b_sig_t)(neighbours*);// указатели на методы Snoopy


typedef  struct {// Структура, отражающая всю информацию о сигнале
	Owner* handler;// обработчик
	slt_ptr_t slot;// метод обработчика
	int sig_num;
}sig_info_t;

typedef  struct {// форма, аналогичная форме задания связей
	Snoopy* transmitter;
	Owner* handler;
	sig_ptr_t signal;
}input_form_t;

typedef  struct {// структура для вызова метода emit_signal
	Snoopy* transmitter;
	sig_ptr_t signal;
}emit_struct_t; 


typedef std::pair<slt_ptr_t, sig_info_t*> transm_info_t;// полная информация о связи сигнал-обработчик
typedef std::vector<transm_info_t> connects_t;// разъемы 
typedef std::vector<emit_struct_t> unique_callers_vec_t; // список уникальных объектов-передатчиков и их связных праметров
typedef std::queue<input_form_t> link_queue_t;// очередь объявления связей 

#endif
