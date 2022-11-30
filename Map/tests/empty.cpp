#include <map>
#include <iostream>
#include <utility>
#include "../map.hpp"
 
int main()
{
    std::map<int,int> stdNumbers;
	std::map<int,int> ftNumbers;
	
	std::cout << "STD:\n";
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << stdNumbers.empty() << '\n';
 
    // stdNumbers.emplace(42, 13);
    stdNumbers.insert(std::make_pair(13317, 123)); 
    std::cout << "After adding elements, numbers.empty(): " << stdNumbers.empty() << '\n';

	std::cout << "FT:\n";
	std::cout << "Initially, numbers.empty(): " << ftNumbers.empty() << '\n';
 
    // stdNumbers.emplace(42, 13);
    ftNumbers.insert(std::make_pair(13317, 123)); 
    std::cout << "After adding elements, numbers.empty(): " << ftNumbers.empty() << '\n';
}