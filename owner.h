#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include <vector>
#include "sructures.h"
#include "snoopes.h"

class Owner{
public:

	//-----���� ��� ���������� ����������� �������� � ������������-----//
	connects_t connections;
	//----------------------protected signals--------------------------//
	virtual void signal_template(std::string&);
	//----------------------protected slots----------------------------//
	virtual void slot_template(std::string&);
	//-----------------------------------------------------------------//

	void set_connection(sig_ptr_t, Snoopy*, slt_ptr_t, const int);// ���������� �����������
	void emit_signal(sig_ptr_t, std::string&);                    // ��������� ������, ����������� �����������
	void delete_connection(const int);                            // ��������� �����


	explicit Owner(const int dim=0);
	void create_field();// ����� ������� ����
	void show_matrix()const;// ����� ������ ����
	neighbours take_3x3(position) const;// ������������ catch{}, ����� �������� ��������� �������
	bool get_el(position) const;// ����� ���������� ������� �� ������� 
private:
	const int dim;// ����������� ����
	std::vector<std::vector<char>> field;// ����
};

#endif
