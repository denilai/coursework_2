#ifndef SNOOPY
#define SNOOPY
#include <string>
#include "sructures.h"

class Owner;

class Snoopy {
protected:
	Owner* handler = nullptr;
	stepper slot = nullptr;
public:
	virtual std::string IsUnitHere(const neighbors) = 0;
	virtual bool emit_signal(const neighbors) = 0;
	virtual void delete_connection() = 0;
	virtual std::string get_name()const=0;
	virtual void set_connection(Owner*, stepper&) = 0;
	virtual ~Snoopy() {};
};


class LeftSnoopy :public Snoopy{
public:
	virtual void delete_connection()override;
	virtual void set_connection(Owner*, stepper&)override;
	virtual bool emit_signal(const neighbors) override;				   // испустить сигнал, опопвестить обработчики
	virtual	std::string IsUnitHere(const neighbors)override;
	virtual std::string get_name()const override;
	friend void process(Owner*);

};

class RightSnoopy :public Snoopy {
public:
	void delete_connection();
	void set_connection(Owner*, stepper&);
	bool emit_signal(const neighbors);				   // испустить сигнал, опопвестить обработчики
	std::string IsUnitHere(const neighbors);
	std::string get_name()const;
	friend void process(Owner*);

};

class TopSnoopy :public Snoopy {
public:
	void delete_connection();
	void set_connection(Owner*, stepper&);
	bool emit_signal(const neighbors);				   // испустить сигнал, опопвестить обработчики
	std::string IsUnitHere(const neighbors);
	std::string get_name()const;
	friend void process(Owner*);

};

class BotSnoopy :public Snoopy {
public:
	void delete_connection();
	void set_connection(Owner*, stepper&);
	bool emit_signal(const neighbors);				   // испустить сигнал, опопвестить обработчики
	std::string IsUnitHere(const neighbors);
	std::string get_name()const;
	friend void process(Owner*);

};

#endif
