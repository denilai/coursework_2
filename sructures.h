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
}neighbors;

class Owner;
class Snoopy;
class LeftSnoopy;
class RightSnoopy;
class TopSnoopy;
class BotSnoopy;

typedef std::string(LeftSnoopy::* lsnooper)(neighbors*);// методы поиска единицы слева
typedef std::string(RightSnoopy::* rsnooper)(neighbors*);// методы поиска единицы справа
typedef std::string(TopSnoopy::* tsnooper)(neighbors*);// методы поиска единицы сверху
typedef std::string(BotSnoopy::* bsnooper)(neighbors*);// методы поиска единицы снизу
typedef void (Owner::* stepper)(std::string&);// методы замены и шагов
typedef neighbors*(Owner::* looper)(void);// методы проведения итераций

typedef struct {
	tsnooper tsnp;
	rsnooper rsnp;
	bsnooper bsnp;
	lsnooper lsnp;	
} snoopers;// метод обработчика

typedef  struct {// Структура, отражающая всю информацию о сигнале
	Snoopy* handler;// обработчик
	snoopers* slots;
	int sig_num;
}to_snp_info_t;

typedef  struct {// Структура, отражающая всю информацию о сигнале
	Owner* handler;// обработчик
	stepper slot;// метод обработчика
	int sig_num;
}to_own_info_t;

//typedef  struct {// форма, аналогичная форме задания связей
//	Snoopy* transmitter;
//	Owner* handler;
//	sig_ptr_t signal;
//}input_form_t;

//typedef  struct {// структура для вызова метода emit_signal
//	Snoopy* transmitter;
//	sig_ptr_t signal;
//}emit_struct_t; 


typedef std::pair<looper, to_snp_info_t*> to_snp_pair_t;// полная информация о связи Owner->Snoopy
typedef std::vector<to_snp_pair_t> own_connects_t;// разъемы класса Owner

typedef std::pair<snoopers*, to_own_info_t*> to_own_pair_t;// полная информация о связи Snoopy->Owner
typedef std::vector<to_own_pair_t> snp_connects_t;// разъемы класса Snoopy

//typedef std::vector<emit_struct_t> unique_callers_vec_t; // список уникальных объектов-передатчиков и их связных праметров
//typedef std::queue<input_form_t> link_queue_t;// очередь объявления связей 

#endif
