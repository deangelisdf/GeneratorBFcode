#pragma once

#define MAX_DIM_MEM_GENERATOR 128
#include <string>

class GeneratorBF
{
private:
	//char memory[MAX_DIM_MEM_GENERATOR];//temporary mem
	//char *ptr,*start_mem,*end_mem;

	/*
	@brief: this function erase the memory saved in "memory" buffer.
	*/
	//void clearMem();

	char getMax(const std::string & result);
	char getMin(const std::string & result);
	/*
	@brief: Euclidean's algorithm for great common divisor
	*/
	int gcb(unsigned char a, unsigned char b);
	int firstCycle(const std::string & result, std::string& result_prog);
	std::string getCycle(int& buffer, char desired_value);
public:
	GeneratorBF() { 
		/*start_mem = memory;
		end_mem = start_mem + MAX_DIM_MEM_GENERATOR;
		this->clearMem();*/
	}
	/*
	 @brief: it generate a brainfuck program. It must fill out the memory with same string passed on "result"
			 this implementation is based on 2 bytes-buffer
	 @param[result]: input parameter, this is the desired result
	 @param[result_prog]: output parameter, this is the generated BF program
	*/
	void generate(const std::string& result, std::string& result_prog);
	void generateN(const std::string& result, std::string& result_prog);
};

