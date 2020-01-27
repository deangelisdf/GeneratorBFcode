#include "GeneratorBF.h"

char GeneratorBF::getMax(const std::string & result)
{
	char val = 0;
	auto end = result.end();
	for (auto i = result.begin(); i != end; i++) {
		if (val < (*i)) val = (*i);
	}
	return val;
}

char GeneratorBF::getMin(const std::string & result)
{
	unsigned char val=255;
	auto end = result.end();
	for (auto i = result.begin(); i != end; i++) {
		if (val > (*i)) val = (*i);
	}
	return val;
}

int GeneratorBF::gcb(unsigned char a, unsigned char b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int GeneratorBF::firstCycle(const std::string & result,std::string& result_prog)
{
	char minChar = this->getMin(result);
	char maxChar = this->getMax(result);
	int gcb_char;
	do {
		gcb_char = this->gcb(maxChar, minChar);
		maxChar--;
	} while (gcb_char==1);
	int gcb_b = minChar / gcb_char;
	result_prog.append(gcb_char,'+');//fill first memory location with a value like the "great common divider"
	result_prog += "[->";
	result_prog.append(gcb_b,'+');
	result_prog += "<]>";
	return gcb_char * gcb_b;
}

std::string GeneratorBF::getCycle(int& buffer,char desired_value)
{
	std::string res="<";
	int remain = (int)buffer - (int)desired_value;
	char op = (remain > 0) ? '-' : '+';
	remain = std::abs(remain);
	res.append(4, '+');
	res += "[->";
	res.append(remain>>2, op);
	res += "<]>";
	if (remain & 3)
		res.append(remain & 3,op);
	buffer = desired_value;
	return res;
}

void GeneratorBF::generate(const std::string & result, std::string & result_prog)
{
	result_prog.clear();
	int val = this->firstCycle(result, result_prog); //first pointer is index, second is value, now we stay on value
	auto end = result.end();
	for (auto i = result.begin(); i != end; i++) {
		if (std::abs((*i) - val) > 10) {
			result_prog += this->getCycle(val, (*i));
		}
		else {
			if ((*i) - val > 0) {
				result_prog.append((*i) - val, '+');
				val += (*i) - val;
			}
			else if ((*i) - val < 0) {
				result_prog.append(val - (*i), '-');
				val -= val - (*i);
			}
		}
		result_prog += '.';
	}
}

void GeneratorBF::generateN(const std::string & result, std::string & result_prog)
{

}
