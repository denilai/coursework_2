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
}neighbours;

class Owner;
class Snoopy;
class LeftSnoopy;
class RightSnoopy;
class TopSnoopy;
class BotSnoopy;

typedef std::string(Snoopy::* sig_ptr_t)(neighbours*);// ��������� �� ������ Snoopy
typedef position (Owner::*slt_ptr_t)(neighbours);// ��������� �� ������ Owner

//typedef std::string(Snoopy::*r_sig_t)(neighbours*);// ��������� �� ������ Snoopy
//typedef std::string(Snoopy::*t_sig_t)(neighbours*);// ��������� �� ������ Snoopy
//typedef std::string(Snoopy::*b_sig_t)(neighbours*);// ��������� �� ������ Snoopy


typedef  struct {// ���������, ���������� ��� ���������� � �������
	Owner* handler;// ����������
	slt_ptr_t slot;// ����� �����������
	int sig_num;
}sig_info_t;

typedef  struct {// �����, ����������� ����� ������� ������
	Snoopy* transmitter;
	Owner* handler;
	sig_ptr_t signal;
}input_form_t;

typedef  struct {// ��������� ��� ������ ������ emit_signal
	Snoopy* transmitter;
	sig_ptr_t signal;
}emit_struct_t; 


typedef std::pair<slt_ptr_t, sig_info_t*> transm_info_t;// ������ ���������� � ����� ������-����������
typedef std::vector<transm_info_t> connects_t;// ������� 
typedef std::vector<emit_struct_t> unique_callers_vec_t; // ������ ���������� ��������-������������ � �� ������� ���������
typedef std::queue<input_form_t> link_queue_t;// ������� ���������� ������ 

#endif
