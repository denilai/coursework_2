#include "snoopes.h"

Snoopy::~Snoopy() {}

std::string LeftSnoopy::IsUnitHere(neighbours* symb) {
	return symb->left ? "signal_1" : "signal_2";
}
std::string LeftSnoopy::get_name()const { return "LeftSnoopy"; }
LeftSnoopy::~LeftSnoopy() {}

std::string RightSnoopy::IsUnitHere(neighbours* symb) {
	return symb->right ? "signal_1" : "signal_2";
}
std::string RightSnoopy::get_name()const { return "RightSnoopy"; }
RightSnoopy::~RightSnoopy() {}

std::string TopSnoopy::IsUnitHere(neighbours* symb) {
	return symb->top ? "signal_1" : "signal_2";
}
std::string TopSnoopy::get_name()const { return "TopSnoopy"; }
TopSnoopy::~TopSnoopy() {}

std::string BotSnoopy::IsUnitHere(neighbours* symb) {
	return symb->bot ? "signal_1" : "signal_2";
}
std::string BotSnoopy::get_name()const { return "BotSnoopy"; }
BotSnoopy::~BotSnoopy() {}