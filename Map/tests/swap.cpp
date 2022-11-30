#include "../map.hpp"
#include <iostream>
#include <string>
#include <map>

int main()
{
  	std::map<int,char> stdNums;
	std::map<int,char> stdNums2;

	stdNums.insert(std::make_pair<int, char> (1, 'a'));
	stdNums.insert(std::make_pair<int, char> (3, 'b'));
	stdNums2.insert(std::make_pair<int, char> (5, 'c'));
	stdNums2.insert(std::make_pair<int, char> (7, 'd'));

	ft::map<int,char> ftNums;
	ft::map<int,char> ftNums2;

	ftNums.insert(ft::make_pair<int, char> (1, 'a'));
	ftNums.insert(ft::make_pair<int, char> (3, 'b'));
	ftNums2.insert(ft::make_pair<int, char> (5, 'c'));
	ftNums2.insert(ft::make_pair<int, char> (7, 'd'));
 
   	std::cout << "STD: \n";
	std::cout << "stdNums: ";
	for (std::map<int,char>::iterator it = stdNums.begin(); it != stdNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	std::cout << "stdNums2: ";
	for (std::map<int,char>::iterator it = stdNums2.begin(); it != stdNums2.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	stdNums.swap(stdNums2);
	std::cout << "stdNums: ";
	for (std::map<int,char>::iterator it = stdNums.begin(); it != stdNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "FT: \n";
	std::cout << "ftNums: ";
	for (ft::map<int,char>::iterator it = ftNums.begin(); it != ftNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	std::cout << "ftNums2: ";
	for (ft::map<int,char>::iterator it = ftNums2.begin(); it != ftNums2.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
	ftNums.swap(ftNums2);
	std::cout << "ftNums: ";
	for (ft::map<int,char>::iterator it = ftNums.begin(); it != ftNums.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;



	


}