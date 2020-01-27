#pragma once
#include "Instr.h"
class InstrPtrDec : public Instr {
public:
	virtual void exec(char*&mem) {
		--mem;
	}
};