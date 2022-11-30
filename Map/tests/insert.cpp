#include "../map.hpp"
#include <iostream>
#include <string>
#include <map>

void	printStd(std::map<std::string, int> & stdMap1)
{
	std::cout << "STD: ";
	for (std::map<std::string, int>::iterator it = stdMap1.begin(); it != stdMap1.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
}

void	printFt(ft::map<std::string, int> & ftMap1)
{
	std::cout << "FT: ";
	for (ft::map<std::string, int>::iterator it = ftMap1.begin(); it != ftMap1.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
}

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

	printStd(stdMap1);
	printFt(ftMap1);

	std::map<std::string, int> stdMap2;
	ft::map<std::string, int> ftMap2;

	stdMap2.insert(stdMap1.begin(),stdMap1.end());
	printStd(stdMap2);


	ftMap2.insert(ftMap1.begin(),ftMap1.end());
	printFt(ftMap2);

	stdMap2.insert(stdMap2.begin(),std::make_pair<std::string, int> ("new", 42));
	printStd(stdMap2);

	ftMap2.insert(ftMap2.begin(),ft::make_pair<std::string, int> ("new", 42));
	printFt(ftMap2);


}