#ifndef SNOOPY
#define SNOOPY
#include "sructures.h"
#include <string>

class Snoopy {
	// суперкласс для всех ищеек (Snoopy)
	// Нужен для того, чтобы иметь доступ ко всем экземплярам
	// ищеек через указатель на родительский класс
public:
	virtual std::string get_name()const { return ""; }
	virtual std::string IsUnitHere(neighbours*) { return ""; }
protected:
	virtual ~Snoopy();
};

class LeftSnoopy :public Snoopy{
public:
	std::string IsUnitHere(neighbours*);
	std::string get_name()const;
	virtual ~LeftSnoopy();
};

class RightSnoopy :public Snoopy {
public:
	std::string IsUnitHere(neighbours*)override final;
	virtual std::string get_name()const override;
	virtual ~RightSnoopy();
};

class TopSnoopy :public Snoopy {
public:
	std::string IsUnitHere(neighbours*)override final;
	virtual std::string get_name()const override;
	virtual ~TopSnoopy();
};

class BotSnoopy :public Snoopy {
public:
	std::string IsUnitHere(neighbours*)override final;
	virtual std::string get_name()const override;
	virtual ~BotSnoopy();
};

#endif
