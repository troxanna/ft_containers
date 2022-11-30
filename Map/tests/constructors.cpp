#include <iomanip>
#include <iostream>
#include <string>
#include <map>
#include "../map.hpp"
 
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

	stdMap1["something"] = 69;
	stdMap1["anything"] = 199;
	stdMap1["that thing"] = 50;
	ft::map<std::string, int> ftMap1;
	// std::cout << "ftMap1 something: " << ftMap1["something"] << std::endl;
	ftMap1["something"] = 69;
	ftMap1["anything"] = 199;
	ftMap1["that thing"] = 50;
	printStd(stdMap1);
	printFt(ftMap1);

	std::cout << "ftMap1 count " << ftMap1.empty() << std::endl;
	std::cout << "stdMap1 count " << stdMap1.empty() << std::endl;

 
//   // (4) Range constructor
	std::map<std::string, int> stdIter(stdMap1.find("anything"), stdMap1.end());
	printStd(stdIter);
	printStd(stdMap1);

	ft::map<std::string, int> ftIter(ftMap1.find("anything"), ftMap1.end());
	printFt(ftIter);
	printFt(ftMap1);
 
//   // (6) Copy constructor
	std::map<std::string, int> stdCopied(stdMap1);
	printStd(stdCopied);
	printStd(stdMap1);

	ft::map<std::string, int> ftCopied(ftMap1);
	printFt(ftCopied);
	printFt(ftMap1);

}