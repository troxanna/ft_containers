#include <map>
#include <iostream>
#include "../map.hpp"
 
int main()
{ 
    std::map<int,char> stdNums;

	stdNums.insert(std::make_pair<int, char> (1, 'a'));
	stdNums.insert(std::make_pair<int, char> (2, 'c'));
	stdNums.insert(std::make_pair<int, char> (3, 'b'));

	ft::map<int,char> ftNums;

	ftNums.insert(ft::make_pair<int, char> (1, 'a'));
	ftNums.insert(ft::make_pair<int, char> (2, 'c'));
	ftNums.insert(ft::make_pair<int, char> (3, 'b'));
 
	// stdNums.equal_range(5);

	std::cout << "STD: \n";
	std::cout << '(' << (stdNums.equal_range(1).first).operator*().first << ':' << (stdNums.equal_range(1).first).operator*().second << ") ";
	std::cout << '(' << (stdNums.equal_range(1).second).operator*().first << ':' << (stdNums.equal_range(1).second).operator*().second << ") ";

	std::cout << std::endl;
	std::cout << "FT: \n";
	std::cout << '(' << (ftNums.equal_range(1).first).operator*().first << ':' << (ftNums.equal_range(1).first).operator*().second << ") ";
	std::cout << '(' << (ftNums.equal_range(1).second).operator*().first << ':' << (ftNums.equal_range(1).second).operator*().second << ") ";
	std::cout << std::endl;
}