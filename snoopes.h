#ifndef SNOOPY
#define SNOOPY
#include <string>
#include "sructures.h"

class Owner;
class Snoopy {
	// суперкласс для всех ищеек (Snoopy)
	// Нужен для того, чтобы иметь доступ ко всем экземплярам
	// ищеек через указатель на родительский класс
public:
	virtual std::string get_name()const = 0;
	virtual std::string IsUnitHere(neighbors*) = 0;
	virtual void set_connection(Owner*, stepper)final; // установить соеднинение
	virtual void emit_signal(neighbors*) = 0 ;   // испустить сигнал, опопвестить обработчики
	virtual void delete_connection()final;       // разорвать связь
	neighbors* loop_survey();						// опрос обработчиков на текущей итерации
protected:
	stepper* slot;
	Owner* header=nullptr;
	
	virtual ~Snoopy();
};

class LeftSnoopy :public Snoopy{
public:
	virtual void emit_signal(neighbors*) final;				   // испустить сигнал, опопвестить обработчики
	virtual std::string IsUnitHere(neighbors*) override final;
	virtual std::string get_name()const override final;
};

class RightSnoopy :public Snoopy {
public:
	virtual void emit_signal(neighbors*) final;				   // испустить сигнал, опопвестить обработчики
	virtual std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
};

class TopSnoopy :public Snoopy {
public:
	virtual void emit_signal(neighbors*) final;				   // испустить сигнал, опопвестить обработчики
	virtual std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
};

class BotSnoopy :public Snoopy {
public:
	virtual void emit_signal(neighbors*) final;				   // испустить сигнал, опопвестить обработчики
	virtual std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
};

#endif
