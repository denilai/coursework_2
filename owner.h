#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include <vector>
#include "sructures.h"
#include "snoopes.h"

class Owner{
public:

	//-----���� ��� ���������� ����������� �������� � ������������-----//
	own_connects_t connections;
	//----------------------protected signals--------------------------//
	//virtual void signal_template(std::string&);
	//----------------------protected slots----------------------------//
	//virtual void slot_template(std::string&);
	//-----------------------------------------------------------------//

	void set_connection(looper, Snoopy*, snooper, const int); // ���������� �����������
	void emit_signal(looper);						          // ��������� ������, ����������� �����������
	void delete_connection(const int);                            // ��������� �����
	neighbors* loop_survey();											// ����� ������������ �� ������� ��������

	explicit Owner(const int dim=0);
	void create_field(std::istream*);// ����� ������� ����
	void show_matrix()const;// ����� ������ ����
	neighbors take_neigh(position) const;// ������������ catch{}, ����� �������� ��������� �������
	bool get_el(position) const;// ����� ���������� ������� �� ������� 
	void find_first_unit();
	friend void process(std::istream*, Owner*);
private:
	const int dim;// ����������� ����
	std::vector<std::vector<char>> field;// ����
	position current_unit;// ���������� ��������� ��������� �������
};

#endif
