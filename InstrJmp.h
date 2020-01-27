#pragma once
#include "Instr.h"

class InstrJmp : public Instr {
private:
	Instr* backup_next;
	bool saved;
	Instr* ip_label;//address next instruction after label
public:
	InstrJmp() :backup_next(nullptr),saved(false) {};
	void setLabel(Instr* l) { this->ip_label = l; }
	virtual void exec(char*&mem) {
		if (saved) {
			this->next = this->backup_next;
			saved = false;
			this->backup_next = nullptr;
		}
		if (*mem) {
			backup_next = this->next;
			saved = true;
			this->next = ip_label;
		}
	}
};