#include <iostream>
#include <locale>
#include <map>
#include "../map.hpp"
 
int main()
{
    std::map<char, char> q;
	ft::map<char, char> p;
    std::cout.imbue(std::locale("en_US.UTF-8"));    
    std::cout << "Maximum size of a std::map is " << q.max_size() << '\n';
	std::cout << "Maximum size of a ft::map is " << p.max_size() << '\n';
}