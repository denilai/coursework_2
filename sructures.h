#ifndef STRUCTURES
#define STRUCTURES
#include <vector>
#include <string>

class Owner;
class Snoopy;
class LeftSnoopy;
class RightSnoopy;
class TopSnoopy;
class BotSnoopy;

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

typedef std::string(LeftSnoopy::* lsnooper)(neighbors*);		// методы поиска единицы слева
typedef std::string(RightSnoopy::* rsnooper)(neighbors*);		// методы поиска единицы справа
typedef std::string(TopSnoopy::* tsnooper)(neighbors*);			// методы поиска единицы сверху
typedef std::string(BotSnoopy::* bsnooper)(neighbors*);			// методы поиска единицы снизу

typedef void (Owner::* stepper)(std::string);					// методы замены и шагов
typedef neighbors*(Owner::* looper)(void);						// методы проведения итераций

typedef struct {//  стурктура всех указателей на методы объектов-обработчиков
	tsnooper tsnp;
	rsnooper rsnp;
	bsnooper bsnp;
	lsnooper lsnp;	
} snoopers;					

typedef struct {//  стурктура всех указателей объекты-обработчики
	TopSnoopy* top;
	RightSnoopy* right;
	BotSnoopy* bot;
	LeftSnoopy* left;
}pack;

typedef  struct {// Структура, отражающая всю информацию о сигнале
	pack handlers;// обработчик
	snoopers *slots;
	int sig_num;
}to_snp_info_t;

typedef  struct {// Структура, отражающая всю информацию о сигнале
	Owner* handler;// обработчик
	stepper* slot;// методы обработчика
	int sig_num;
}to_own_info_t;

typedef std::pair<looper, to_snp_info_t*> to_snp_pair_t;// полная информация о связи Owner->Snoopy

#endif
