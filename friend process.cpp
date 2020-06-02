#include "owner.h";
#include "snoopes.h"
#include "sructures.h"

char& operator%(Owner* matrix, position pos){
	if (pos.col < 0 || pos.row < 0)
		throw 'a';
	if (pos.col >= matrix->field.size() || pos.row >= matrix->field.size())
		throw 'b';
	return matrix->field[pos.row][pos.col];
}

void process(Owner* matrix){
	if (matrix->get_curr_unit().row == -1) {
		matrix->show_matrix();
		return;
	}
	TopSnoopy Top;
	RightSnoopy Right;
	BotSnoopy Bot;
	LeftSnoopy Left;
	pack headers = { &Top,&Right,&Bot,&Left };

	tsnooper top = &TopSnoopy::emit_signal;
	rsnooper right = &RightSnoopy::emit_signal;
	bsnooper bot = &BotSnoopy::emit_signal;
	lsnooper left = &LeftSnoopy::emit_signal;
	snoopers slots = { top,right,bot,left };

	looper loop = &Owner::loop_survey;
	stepper step = &Owner::step;
	neighbors a{ 1,1,1,1 };

	matrix->set_connection(loop, headers, slots, 1);
	Top.set_connection(matrix, step);
	Right.set_connection(matrix, step);
	Bot.set_connection(matrix, step);
	Left.set_connection(matrix, step);
	for (;;)
		if (!matrix->emit_signal(loop))
			break;
	matrix->show_matrix();
}