#ifndef STRUCTURES
#define STRUCTURES
#include <vector>
#include <string>

class Owner;
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

typedef bool(LeftSnoopy::* lsnooper)(neighbors const);			// методы поиска единицы слева
typedef bool(RightSnoopy::* rsnooper)(neighbors const);			// методы поиска единицы справа
typedef bool(TopSnoopy::* tsnooper)(neighbors const);			// методы поиска единицы сверху
typedef bool(BotSnoopy::* bsnooper)(neighbors const);			// методы поиска единицы снизу

typedef bool (Owner::* stepper)(std::string);					// методы замены и шагов
typedef neighbors(Owner::* looper)(void);						// методы проведения итераций

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
	snoopers slots;// ****
	int sig_num;
}to_snp_info_t;

//typedef  struct {// Структура, отражающая всю информацию о сигнале
//	Owner* handler;// обработчик
//	stepper* slot;// методы обработчика
//	int sig_num;
//}to_own_info_t;

typedef std::pair<looper, to_snp_info_t> to_snp_pair_t;// полная информация о связи Owner->Snoopy

#endif
