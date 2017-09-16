#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

#include "IniParser.hpp"


           	

IniParser::~IniParser() {
	for (auto &i : data)
		delete i.second;
} 


void IniParser::Initialize(std::string const &file_name) {
	std::cerr << "Initialize started file_name: " << file_name << '\n';
	in.open(file_name);
	std::cerr << "file opened\n";
	if (!in.good())
		std::cerr << "File IO error while opening\n";
	std::string line, section_name;
	while (getline(in, line)) {
		line = ClearLine(line);
		std::cerr << "now line : "  << line << '\n';
		if (IsSection(line)) {
			std::cerr << "new Section\n";
			section_name = line.substr(1, (size_t)line.size() - 2);
			std::cerr << "Section name : " << section_name << '\n';
			data[section_name] = new Section();
			continue;
		}

		if (IsParam(line)) {
			std::string param_name, value;
			bool was_equal = false;
			for (int i = 0; i < (int)line.size(); i++) {
				if (line[i] == '=') {
					was_equal = true;
					continue;
				}
				if (!was_equal)
					param_name += line[i];
				else
					value += line[i];
			}
			data[section_name]->add(param_name, value);	
		}
	}	
	in.close();
	std::cerr << "Initialize finished file_name: " << file_name << "\n\n";
}	

bool IniParser::IsHaveSection(std::string const &section_name) const {
	return data.find(section_name) != data.end();
}	


bool IniParser::IsHaveParam(std::string const &section_name, std::string const &param_name) const {
	if (IsHaveSection(section_name))
		return data.at(section_name)->exists(param_name);
	return false;
}	

	
std::string IniParser::ClearLine(std::string const &s) const {
    std::string ans;
    for (int i = 0; i < (int)s.size(); i++) {
    	if (s[i] == ';') break;
    	if (s[i] == ' ') continue;
    	ans += s[i];
    }	
    return ans;
}	
    		
bool IniParser::IsSection(std::string const &s) const {
	return s[0] == '[' && s.back() == ']';
}	

bool IniParser::IsParam(std::string const &s) const {
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '=') 
			return true;
	}
	return false;
}
		