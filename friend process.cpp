#include "owner.h";
#include "snoopes.h"
#include "sructures.h"

//void process(Owner* matrix, TopSnoopy* Top, RightSnoopy* Right, BotSnoopy* Bot, LeftSnoopy* Left) {
void process(Owner* matrix){
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

}