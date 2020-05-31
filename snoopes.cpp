#include "sructures.h"
#include "snoopes.h"
#include "owner.h"

//------------------------------------class Snoopy---------------------------------//

void Snoopy::set_connection( Owner* header, stepper slot) {
	delete_connection();
	this->header =  new Owner (header);
	this->slot =new stepper(slot);
}

void Snoopy::delete_connection() {
	delete header;
	delete slot;
}
Snoopy::~Snoopy() {}

//------------------------------------class LeftSnoopy---------------------------------//

std::string LeftSnoopy::IsUnitHere(neighbors* symb) {
	return symb->left ? "signal_1" : "signal_2";
}

std::string LeftSnoopy::get_name()const { return "LeftSnoopy"; }

void LeftSnoopy::emit_signal(neighbors* symb) {
	//std::string answer = IsUnitHere(symb);
	(header->*(*slot))(IsUnitHere(symb));
}
//------------------------------------class RightSnoopy---------------------------------//

std::string RightSnoopy::IsUnitHere(neighbors* symb) {
	return symb->right ? "signal_1" : "signal_2";
}

std::string RightSnoopy::get_name()const { return "RightSnoopy"; }

//------------------------------------class TopSnoopy---------------------------------//

std::string TopSnoopy::IsUnitHere(neighbors* symb) {
	return symb->top ? "signal_1" : "signal_2";
}

std::string TopSnoopy::get_name()const { return "TopSnoopy"; }

//------------------------------------class BotSnoopy---------------------------------//

std::string BotSnoopy::IsUnitHere(neighbors* symb) {
	return symb->bot ? "signal_1" : "signal_2";
}

std::string BotSnoopy::get_name()const { return "BotSnoopy"; }

//-------------------------------------------------------------------------------------//
