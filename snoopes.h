#ifndef SNOOPY
#define SNOOPY
#include "sructures.h"
#include <string>

class Snoopy {
	// ���������� ��� ���� ����� (Snoopy)
	// ����� ��� ����, ����� ����� ������ �� ���� �����������
	// ����� ����� ��������� �� ������������ �����
public:
	virtual std::string get_name()const = 0;
protected:
	virtual ~Snoopy();
};

class LeftSnoopy :public Snoopy {
public:
	std::string IsUnitOnLeft(neighbours);
	virtual std::string get_name()const override;
	virtual ~LeftSnoopy();
};

class RightSnoopy :public Snoopy {
public:
	std::string IsUnitOnRight(neighbours);
	virtual std::string get_name()const override;
	virtual ~RightSnoopy();
};

class TopSnoopy :public Snoopy {
public:
	std::string IsUnitOnTop(neighbours);
	virtual std::string get_name()const override;
	virtual ~TopSnoopy();
};

class BotSnoopy :public Snoopy {
public:
	std::string IsUnitOnBot(neighbours);
	virtual std::string get_name()const override;
	virtual ~BotSnoopy();
};

#endif
