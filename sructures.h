#ifndef STRUCTURES
#define STRUCTURES
#include <queue>
#include <string>


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

class Owner;
class Snoopy;
class LeftSnoopy;
class RightSnoopy;
class TopSnoopy;
class BotSnoopy;

typedef std::string(LeftSnoopy::* lsnooper)(neighbors*);// ������ ������ ������� �����
typedef std::string(RightSnoopy::* rsnooper)(neighbors*);// ������ ������ ������� ������
typedef std::string(TopSnoopy::* tsnooper)(neighbors*);// ������ ������ ������� ������
typedef std::string(BotSnoopy::* bsnooper)(neighbors*);// ������ ������ ������� �����
typedef void (Owner::* stepper)(std::string&);// ������ ������ � �����
typedef neighbors*(Owner::* looper)(void);// ������ ���������� ��������

typedef struct {
	tsnooper tsnp;
	rsnooper rsnp;
	bsnooper bsnp;
	lsnooper lsnp;	
} snoopers;// ����� �����������

typedef  struct {// ���������, ���������� ��� ���������� � �������
	Snoopy* handler;// ����������
	snoopers* slots;
	int sig_num;
}to_snp_info_t;

typedef  struct {// ���������, ���������� ��� ���������� � �������
	Owner* handler;// ����������
	stepper slot;// ����� �����������
	int sig_num;
}to_own_info_t;

//typedef  struct {// �����, ����������� ����� ������� ������
//	Snoopy* transmitter;
//	Owner* handler;
//	sig_ptr_t signal;
//}input_form_t;

//typedef  struct {// ��������� ��� ������ ������ emit_signal
//	Snoopy* transmitter;
//	sig_ptr_t signal;
//}emit_struct_t; 


typedef std::pair<looper, to_snp_info_t*> to_snp_pair_t;// ������ ���������� � ����� Owner->Snoopy
typedef std::vector<to_snp_pair_t> own_connects_t;// ������� ������ Owner

typedef std::pair<snoopers*, to_own_info_t*> to_own_pair_t;// ������ ���������� � ����� Snoopy->Owner
typedef std::vector<to_own_pair_t> snp_connects_t;// ������� ������ Snoopy

//typedef std::vector<emit_struct_t> unique_callers_vec_t; // ������ ���������� ��������-������������ � �� ������� ���������
//typedef std::queue<input_form_t> link_queue_t;// ������� ���������� ������ 

#endif
