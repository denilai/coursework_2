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
	return symb->left ? "lsignal_1" : "lsignal_2";
}

std::string LeftSnoopy::get_name()const { return "LeftSnoopy"; }

void LeftSnoopy::emit_signal(neighbors* symb) {
	//std::string answer = IsUnitHere(symb);
	(header->*(*slot))(IsUnitHere(symb));
}
//------------------------------------class RightSnoopy---------------------------------//

std::string RightSnoopy::IsUnitHere(neighbors* symb) {
	return symb->right ? "rsignal_1" : "rsignal_2";
}

std::string RightSnoopy::get_name()const { return "RightSnoopy"; }

void RightSnoopy::emit_signal(neighbors* symb) {
	//std::string answer = IsUnitHere(symb);
	(header->*(*slot))(IsUnitHere(symb));
}

//------------------------------------class TopSnoopy---------------------------------//

std::string TopSnoopy::IsUnitHere(neighbors* symb) {
	return symb->top ? "tsignal_1" : "tsignal_2";
}

std::string TopSnoopy::get_name()const { return "TopSnoopy"; }

void TopSnoopy::emit_signal(neighbors* symb) {
	//std::string answer = IsUnitHere(symb);
	(header->*(*slot))(IsUnitHere(symb));
}

//------------------------------------class BotSnoopy---------------------------------//

std::string BotSnoopy::IsUnitHere(neighbors* symb) {
	return symb->bot ? "bsignal_1" : "bsignal_2";
}

std::string BotSnoopy::get_name()const { return "BotSnoopy"; }

void BotSnoopy::emit_signal(neighbors* symb) {
	//std::string answer = IsUnitHere(symb);
	(header->*(*slot))(IsUnitHere(symb));
}

//-------------------------------------------------------------------------------------//
