#include "../map.hpp"
#include <iostream>
#include <string>
#include <map>


int main()
{
  // (1) Default constructor
	std::map<std::string, int> stdMap1;
	// std::cout << "stdMap1 something: " << stdMap1["something"] << std::endl;
	stdMap1.insert(std::make_pair<std::string, int> ("something", 69));
	stdMap1.insert(std::make_pair<std::string, int> ("anything", 199));
	stdMap1.insert(std::make_pair<std::string, int> ("that thing", 50));

	ft::map<std::string, int> ftMap1;
	// std::cout << "ftMap1 something: " << ftMap1["something"] << std::endl;
	ftMap1.insert(ft::make_pair<std::string, int> ("something", 69));
	ftMap1.insert(ft::make_pair<std::string, int> ("anything", 199));
	ftMap1.insert(ft::make_pair<std::string, int> ("that thing", 50));

	std::cout << "STD: ";
	for (std::map<std::string, int>::iterator it = stdMap1.begin(); it != stdMap1.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	std::cout << "FT: ";
	for (ft::map<std::string, int>::iterator it = ftMap1.begin(); it != ftMap1.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;

	std::cout << "STD reverse: ";
	for (std::map<std::string, int>::reverse_iterator it = stdMap1.rbegin(); it != stdMap1.rend(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;

	std::cout << "FT reverse: ";
	for (ft::map<std::string, int>::reverse_iterator it = ftMap1.rbegin(); it != ftMap1.rend(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	
}