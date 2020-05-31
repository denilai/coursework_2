#ifndef SNOOPY
#define SNOOPY
#include "sructures.h"
#include <string>

class Snoopy {
	// суперкласс для всех ищеек (Snoopy)
	// Нужен для того, чтобы иметь доступ ко всем экземплярам
	// ищеек через указатель на родительский класс
public:
	virtual std::string get_name()const = 0;
	virtual std::string IsUnitHere(neighbors*) = 0;
protected:
	virtual ~Snoopy();
};

class LeftSnoopy :public Snoopy{
public:
	std::string IsUnitHere(neighbors*) override final;
	std::string get_name()const override final;
	virtual ~LeftSnoopy();
};

class RightSnoopy :public Snoopy {
public:
	std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
	virtual ~RightSnoopy();
};

class TopSnoopy :public Snoopy {
public:
	std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
	virtual ~TopSnoopy();
};

class BotSnoopy :public Snoopy {
public:
	std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
	virtual ~BotSnoopy();
};

#endif
