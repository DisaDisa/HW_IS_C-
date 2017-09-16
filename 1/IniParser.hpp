#pragma once

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>


struct IniParser {
private:
	struct Section {
		void add(std::string const &name, std::string const &value) {
			std::cerr << "Section::add started\n";
			std::cerr << "name: " << name << '\n';
			std::cerr << "value: " << value << '\n';
			data[name] = value;
			std::cerr << "Section::add finished\n\n";
		}

  		std::string get(std::string const &name) const {
  			std::cerr << "Section::get\n";
  			std::cerr << "name: " << name << "\n\n";
  			return data.at(name);
  		}

 	 	bool exists(std::string const &name) const {
  			std::cerr << "Section::exists\n\n";
  			return data.find(name) != data.end();
  		}
  		
		private:
			std::map <std::string, std::string> data;
	};
public: 

	~IniParser();
	
	// Opens Ini file.
	void Initialize(std::string const &file_name);
		

	// Checks if a section exists.
	bool IsHaveSection(std::string const &section_name) const;
		
	// Checks if a pair param-section exists.
	bool IsHaveParam(std::string const &section_name, std::string const &param_name) const;
	
	// Returns value for a pair param-section.
	template <typename T>
	T GetValue(std::string const &section_name, std::string const &param_name) const {
		std::stringstream ss;
		ss << data.at(section_name)->get(param_name);
		T ans;
		ss >> ans;
		return ans;
	}
	
private:
    std::string ClearLine(std::string const &) const;
    		
	bool IsSection(std::string const &) const;	

	bool IsParam(std::string const &) const;

	
	std::map <std::string, Section *> data;
	std::ifstream in;
};
