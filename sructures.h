#ifndef STRUCTURES
#define STRUCTURES
#include <queue>

typedef struct {// ���������, ��������������
				// ������� ������� ��� ��������� ��������� (����������)
				// �� ���� ������ std::pair
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

typedef void (Owner::* sig_ptr_t)(std::string&);// ��������� �� ������ Owner
typedef void (Snoopy::* slt_ptr_t)(std::string&);// ��������� �� ������ Snoopy

typedef  struct {// ���������, ���������� ��� ���������� � �������
	Snoopy* handler;// ����������
	slt_ptr_t slot;// ����� �����������
	int sig_num;// ������������� �������
}sig_info_t;

typedef  struct {
	int sig_num;
	Owner* transmitter;
	Snoopy* handler;
	sig_ptr_t signal;
}input_form_t;// �����, ����������� ����� ������� ������

typedef  struct {
	Owner* transmitter;
	sig_ptr_t signal;
}emit_struct_t; // ��������� ��� ������ ������ emit_signal


typedef std::pair<sig_ptr_t, sig_info_t*> transm_info_t;// ������ ���������� � ����� ������-����������

typedef std::vector<transm_info_t> connects_t;// ������� 
typedef std::vector<emit_struct_t> unique_callers_vec_t; // ������ ���������� ��������-������������ � �� ������� ���������
typedef std::queue<input_form_t> link_queue_t;// ������� ���������� ������ 

#endif
