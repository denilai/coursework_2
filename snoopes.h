#ifndef SNOOPY
#define SNOOPY
#include "sructures.h"
#include <string>

class Snoopy {
public:
	virtual std::string get_name()const = 0;
private:
	virtual ~Snoopy();
};

class LeftSnoopy:public Snoopy {
	std::string IsUnitOnLeft(neighbours);
	virtual std::string get_name()const override;
};

class RightSnoopy:public Snoopy {
	std::string IsUnitOnRight(neighbours);
	virtual std::string get_name()const override;
};

class TopSnoopy :public Snoopy {
	std::string IsUnitOnTop(neighbours);
	virtual std::string get_name()const override;
};

class BotSnoopy :public Snoopy {
	std::string IsUnitOnBot(neighbours);
	virtual std::string get_name()const override;
};

#endif
