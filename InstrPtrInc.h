#pragma once
#include "Instr.h"
class InstrPtrInc : public Instr {
public:
	virtual void exec(char*&mem) {
		++mem;
	}
};