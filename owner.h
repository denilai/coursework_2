#ifndef MATRIX_MASTER
#define MATRIX_MASTER
#include "sructures.h"


class Owner {
public:


	to_snp_pair_t connections;

	void set_connection(looper, pack, snoopers, const int);		// ���������� �����������
	bool emit_signal(looper);							// ��������� ������, ����������� �����������
	void delete_connection(const int);							// ��������� �����
	neighbors* loop_survey();									// ����� ������������ �� ������� ��������
	bool step(std::string);
	explicit Owner(const int dim = 0);
	Owner(Owner* old);
	void create_field(std::istream*);							// ����� ������� ����
	void show_matrix()const;									// ����� ������ ����
	neighbors take_neighbors(position) const;						// ������������ catch{}, ����� �������� ��������� �������
	//bool get_el(position) const;								// ����� ���������� ������� �� ������� 
	void find_first_unit();
	friend void process(std::istream*, Owner*);
private:
	const int dim;												// ����������� ����
	std::vector<std::vector<char>> field;						// ����
	position current_unit;										// ���������� ��������� ��������� �������
};

#endif
