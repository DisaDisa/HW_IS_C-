#include <iostream>
#include <string>

#include "IniParser.hpp"

int main(int argc, char **argv) {
	std::string file_name = argv[1];
	IniParser p;
	p.Initialize(file_name);
	std::cout << p.IsHaveSection("ADC_DEV") << '\n';
	std::cout << p.IsHaveSection("ADC_DEVV") << '\n';
	std::cout << p.IsHaveParam("ADC_DEV", "BufferLenSeconds") << '\n';
	std::cout << p.IsHaveParam("ADC_DEV", "BufferLenSecondssss") << '\n';
	std::cout << p.GetValue<double>("ADC_DEV", "BufferLenSeconds") << '\n';
	std::cout << p.GetValue<std::string>("COMMON", "DiskCachePath") << '\n';
	return 0;
}	