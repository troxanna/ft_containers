#include <map>
#include <iostream>
#include "../map.hpp"
 
int main()
{ 
    std::map<int,char> stdNums;

	stdNums.insert(std::make_pair<int, char> (1, 'a'));
	stdNums.insert(std::make_pair<int, char> (5, 'c'));
	stdNums.insert(std::make_pair<int, char> (7, 'd'));

	ft::map<int,char> ftNums;

	ftNums.insert(ft::make_pair<int, char> (1, 'a'));
	ftNums.insert(ft::make_pair<int, char> (5, 'c'));
	ftNums.insert(ft::make_pair<int, char> (7, 'd'));
 

	std::cout << "STD: \n";
	std::cout << stdNums.find(1).operator*().second;
	std::cout << std::endl;
	std::cout << stdNums.find(2).operator*().second;
	std::cout << std::endl;
	std::cout << "FT: \n";
	std::cout << ftNums.find(1).operator*().second;
	std::cout << std::endl;
	std::cout << ftNums.find(2).operator*().second;
	std::cout << std::endl;
}