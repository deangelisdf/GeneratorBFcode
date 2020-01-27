#pragma once

#include "Instr.h"
#include <vector>

#define MAX_DIM_BUFFER 1024

Instr* parse(const char*code);
void execute(const char* prog,char* memory);

