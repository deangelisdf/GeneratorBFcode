#pragma once

#include "Instr.h"

class InstrInc : public Instr {
public:
	virtual void exec(char*&mem) {
		++(*mem);
	}
};