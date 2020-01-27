#pragma once

class Instr {
protected:
	Instr* next;
public:
	Instr():next(nullptr){}
	void setNext(Instr* n) { next = n; }
	Instr* getNext() const { return next; }
	virtual void exec(char*&) = 0;
};