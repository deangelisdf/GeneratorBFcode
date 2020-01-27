#include "ParserBF.h"
#include <stack>
#include "InstrJmp.h"
#include "InstrJmpCond.h"
#include "InstrCout.h"
#include "InstrCin.h"
#include "InstrInc.h"
#include "InstrDec.h"
#include "InstrPtrDec.h"
#include "InstrPtrInc.h"

void execute(const char* prog,char* memory) {
	char*ptr_mem = memory;
	char *start_mem = memory, *end_mem = memory + MAX_DIM_BUFFER;
	clear_memory(memory);
	Instr* code = parse(prog);

	while (code != nullptr) {
		code->exec(ptr_mem);

		if (ptr_mem < start_mem) ptr_mem = end_mem - 1;
		else if (ptr_mem > end_mem) ptr_mem = start_mem;

		code = code->getNext();
	}
}

Instr* parse(const char * code)
{
	std::stack<InstrJmpCond*> blocks;
	Instr* ptr = nullptr;
	Instr* result = nullptr,*first = nullptr;
	while (*code) {
		switch (*code)
		{
		case '+':
			ptr = new InstrInc();
			break;
		case '-':
			ptr = new InstrDec();
			break;
		case '>':
			ptr = new InstrPtrInc();
			break;
		case '<':
			ptr = new InstrPtrDec();
			break;
		case '.':
			ptr = new InstrCout();
			break;
		case ',':
			ptr = new InstrCin();
			break;
		case '[':
			ptr = new InstrJmpCond();
			blocks.push((InstrJmpCond*)ptr);
			break;
		case ']':
			ptr = new InstrJmp();
			blocks.top()->setLabel(ptr);
			((InstrJmp*)ptr)->setLabel(blocks.top());
			blocks.pop();
			break;
		default:
			ptr = nullptr;
			break;
		}
		if (ptr) {
			if (result != nullptr)
				result->setNext(ptr);
			else
				first = ptr;
			result = ptr;
		}
		code++;
	}
	return first;
}

void clear_memory(char *ptr) {
	for (int i = 0; i < MAX_DIM_BUFFER; i++)
		ptr[i] = 0;
}