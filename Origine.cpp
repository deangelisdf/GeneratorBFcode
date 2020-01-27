#include <iostream>
#include <cstdlib>
#include "GeneratorBF.h"
#include "ParserBF.h"

int main() {
	char memory[MAX_DIM_BUFFER] = { 0 };
	GeneratorBF g;
	std::string prog,input;
	while (1) {
		std::getline(std::cin, input);
		system("cls");
		g.generate(input, prog);
		std::cout << prog.c_str() << std::endl;
		execute(prog.c_str(), memory);
	}
	system("pause");
	return 0;
}