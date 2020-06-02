#ifndef SNOOPY
#define SNOOPY
#include <string>
#include "sructures.h"

class Owner;


class LeftSnoopy{
public:
	Owner* handler = nullptr;
	stepper slot = nullptr;
	void delete_connection();
	void set_connection(Owner*, stepper&);
	bool emit_signal(const neighbors) ;				   // испустить сигнал, опопвестить обработчики
	std::string IsUnitHere(const neighbors);
	std::string get_name()const;
	//friend void process(Owner* matrix, TopSnoopy* Top, RightSnoopy* Right, BotSnoopy* Bot, LeftSnoopy* Left);
	friend void process(Owner*);

};

class RightSnoopy  {
public:
	Owner* handler;
	stepper slot;
	void delete_connection();
	void set_connection(Owner*, stepper&);
	bool emit_signal(const neighbors);				   // испустить сигнал, опопвестить обработчики
	std::string IsUnitHere(const neighbors);
	std::string get_name()const;
	//friend void process(Owner* matrix, TopSnoopy* Top, RightSnoopy* Right, BotSnoopy* Bot, LeftSnoopy* Left);
	friend void process(Owner*);

};

class TopSnoopy  {
public:
	Owner* handler;
	stepper* slot;
	void delete_connection();
	void set_connection(Owner*, stepper&);
	bool emit_signal(const neighbors);				   // испустить сигнал, опопвестить обработчики
	std::string IsUnitHere(const neighbors);
	std::string get_name()const;
	//friend void process(Owner* matrix, TopSnoopy* Top, RightSnoopy* Right, BotSnoopy* Bot, LeftSnoopy* Left);
	friend void process(Owner*);

};

class BotSnoopy  {
public:
	Owner* handler = nullptr;
	stepper slot = nullptr;
	void delete_connection();
	void set_connection(Owner*, stepper&);
	bool emit_signal(const neighbors);				   // испустить сигнал, опопвестить обработчики
	std::string IsUnitHere(const neighbors);
	std::string get_name()const;
	//friend void process(Owner* matrix, TopSnoopy* Top, RightSnoopy* Right, BotSnoopy* Bot, LeftSnoopy* Left);
	friend void process(Owner*);

};

#endif
