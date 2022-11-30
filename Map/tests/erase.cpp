#include "../map.hpp"
#include <iostream>
#include <string>
#include <map>

int main()
{
  	std::map<int,char> stdNums;

	stdNums.insert(std::make_pair<int, char> (1, 'a'));
	stdNums.insert(std::make_pair<int, char> (3, 'b'));
	stdNums.insert(std::make_pair<int, char> (5, 'c'));
	stdNums.insert(std::make_pair<int, char> (7, 'd'));

	ft::map<int,char> ftNums;

	ftNums.insert(ft::make_pair<int, char> (1, 'a'));
	ftNums.insert(ft::make_pair<int, char> (3, 'b'));
	ftNums.insert(ft::make_pair<int, char> (5, 'c'));
	ftNums.insert(ft::make_pair<int, char> (7, 'd'));

	std::cout << "STD: ";
	for (std::map<int,char>::iterator it = stdNums.begin(); it != stdNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	std::cout << "FT: ";
	for (ft::map<int,char>::iterator it = ftNums.begin(); it != ftNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
 
    std::cout << "stdNums contains " << stdNums.size() << " elements.\n";
	std::cout << "ftNums contains " << ftNums.size() << " elements.\n";

	stdNums.erase(stdNums.begin());
	ftNums.erase(ftNums.begin());


	std::cout << "STD: ";
	for (std::map<int,char>::iterator it = stdNums.begin(); it != stdNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	std::cout << "FT: ";
	for (ft::map<int,char>::iterator it = ftNums.begin(); it != ftNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;

	std::cout << "stdNums contains " << stdNums.size() << " elements.\n";
	std::cout << "ftNums contains " << ftNums.size() << " elements.\n";

}