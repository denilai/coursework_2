#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include "sructures.h"

class Owner {

private:
	std::vector<std::string> field;								// ����
	to_snp_pair_t connections;
	position current_unit;										// ���������� ��������� ��������� �������
public:
	

	void set_connection(looper, pack, snoopers, const int);		// ���������� �����������
	bool emit_signal(looper);									// ��������� ������, ����������� �����������
	void delete_connection(const int);							// ��������� �����
	char& operator[](position);
	friend char& operator%(Owner*, position);

	neighbors loop_survey();									// ����� ������������ �� ������� ��������
	bool step(std::string);
	explicit Owner(const int dim = 0);
	Owner(const Owner* old);
	position get_curr_unit();
	void create_field(std::istream&);							// ����� ������� ����
	void show_matrix()const;									// ����� ������ ����
	neighbors take_neighbors(position) const;					// ������������ catch{}, ����� �������� ��������� �������
	void find_first_unit();
	friend void process(Owner*);

};

#endif
