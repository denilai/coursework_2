#include "owner.h"
#include "snoopes.h"

int main() {
	Owner field(4);
	field.create_field();
	bool a = field.get_el({1,1});
	return 0;
}