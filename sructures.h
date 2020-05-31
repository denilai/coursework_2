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

typedef struct {// ���������� �������� �� ���� ������ std::pair
	int row;
	int col;
}position;

typedef struct {// ������ ������-���� �������� �������. 
	bool top = false;
	bool right = false;
	bool bot = false;;
	bool left = false;
}neighbors;

typedef std::string(LeftSnoopy::* lsnooper)(neighbors*);		// ������ ������ ������� �����
typedef std::string(RightSnoopy::* rsnooper)(neighbors*);		// ������ ������ ������� ������
typedef std::string(TopSnoopy::* tsnooper)(neighbors*);			// ������ ������ ������� ������
typedef std::string(BotSnoopy::* bsnooper)(neighbors*);			// ������ ������ ������� �����

typedef void (Owner::* stepper)(std::string);					// ������ ������ � �����
typedef neighbors*(Owner::* looper)(void);						// ������ ���������� ��������

typedef struct {//  ��������� ���� ���������� �� ������ ��������-������������
	tsnooper tsnp;
	rsnooper rsnp;
	bsnooper bsnp;
	lsnooper lsnp;	
} snoopers;					

typedef struct {//  ��������� ���� ���������� �������-�����������
	TopSnoopy* top;
	RightSnoopy* right;
	BotSnoopy* bot;
	LeftSnoopy* left;
}pack;

typedef  struct {// ���������, ���������� ��� ���������� � �������
	pack handlers;// ����������
	snoopers *slots;
	int sig_num;
}to_snp_info_t;

typedef  struct {// ���������, ���������� ��� ���������� � �������
	Owner* handler;// ����������
	stepper* slot;// ������ �����������
	int sig_num;
}to_own_info_t;

typedef std::pair<looper, to_snp_info_t*> to_snp_pair_t;// ������ ���������� � ����� Owner->Snoopy

#endif
