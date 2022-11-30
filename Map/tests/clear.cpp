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
 
    std::cout << "stdNums contains " << stdNums.size() << " elements.\n";
	std::cout << "ftNums contains " << ftNums.size() << " elements.\n";

	stdNums.clear();
	ftNums.clear();

	std::cout << "stdNums contains " << stdNums.size() << " elements.\n";
	std::cout << "ftNums contains " << ftNums.size() << " elements.\n";

	


}