#pragma once

#include "Instr.h"

class InstrDec : public Instr {
public:
	virtual void exec(char*&mem) {
		--(*mem);
	}
};