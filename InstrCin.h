#pragma once

#include "Instr.h"
#include <iostream>

class InstrCin : public Instr {
public:
	virtual void exec(char*&mem) {
		std::cin >> mem;
	}
};