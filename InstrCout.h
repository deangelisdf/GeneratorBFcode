#pragma once

#include "Instr.h"
#include <iostream>

class InstrCout : public Instr {
public:
	virtual void exec(char*&mem) {
		std::cout<<(*mem);
	}
};