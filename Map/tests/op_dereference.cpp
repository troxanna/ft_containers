#include "../map.hpp"
#include <iostream>
#include <string>
#include <map>

int main()
{
  // (1) Default constructor
	std::map<std::string, int> stdMap1;
	// std::cout << "stdMap1 something: " << stdMap1["something"] << std::endl;

	stdMap1["something"] = 69;
	stdMap1["anything"] = 199;
	stdMap1["that thing"] = 50;
	ft::map<std::string, int> ftMap1;
	// std::cout << "ftMap1 something: " << ftMap1["something"] << std::endl;
	ftMap1["something"] = 69;
	ftMap1["anything"] = 199;
	ftMap1["that thing"] = 50;

	std::cout << "STD:\n";
	std::cout << "something: " << stdMap1["something"] << std::endl;
	std::cout << "count: " << stdMap1.count("none") << std::endl;
	std::cout << stdMap1["none"] << std::endl;
	std::cout << "count: " << stdMap1.count("none") << std::endl;


	std::cout << "FT:\n";
	std::cout << "something: " << ftMap1["something"] << std::endl;
	std::cout << "count: " << ftMap1.count("none") << std::endl;
	std::cout << ftMap1["none"] << std::endl;
	std::cout << "count: " << ftMap1.count("none") << std::endl;
	


}