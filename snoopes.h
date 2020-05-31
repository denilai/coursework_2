#ifndef SNOOPY
#define SNOOPY
#include <string>
#include "sructures.h"

class Owner;
class Snoopy {
	// ���������� ��� ���� ����� (Snoopy)
	// ����� ��� ����, ����� ����� ������ �� ���� �����������
	// ����� ����� ��������� �� ������������ �����
public:
	virtual std::string get_name()const = 0;
	virtual std::string IsUnitHere(neighbors*) = 0;
	virtual void set_connection(Owner*, stepper)final; // ���������� �����������
	virtual void emit_signal(neighbors*) = 0 ;   // ��������� ������, ����������� �����������
	virtual void delete_connection()final;       // ��������� �����
	neighbors* loop_survey();						// ����� ������������ �� ������� ��������
protected:
	stepper* slot;
	Owner* header=nullptr;
	
	virtual ~Snoopy();
};

class LeftSnoopy :public Snoopy{
public:
	virtual void emit_signal(neighbors*) final;				   // ��������� ������, ����������� �����������
	virtual std::string IsUnitHere(neighbors*) override final;
	virtual std::string get_name()const override final;
};

class RightSnoopy :public Snoopy {
public:
	virtual void emit_signal(neighbors*) final;				   // ��������� ������, ����������� �����������
	virtual std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
};

class TopSnoopy :public Snoopy {
public:
	virtual void emit_signal(neighbors*) final;				   // ��������� ������, ����������� �����������
	virtual std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
};

class BotSnoopy :public Snoopy {
public:
	virtual void emit_signal(neighbors*) final;				   // ��������� ������, ����������� �����������
	virtual std::string IsUnitHere(neighbors*)override final;
	virtual std::string get_name()const override final;
};

#endif
