#include <iostream>         

#include <vector>   
#include "../../Vector/Vector.hpp"    
#include <stack>   
#include "../Stack.hpp"   

int main(){
	std::stack<int> myints;
	ft::stack<int> ft_myints;

	std::cout << "STD:" << std::endl;
	std::cout << "0. size: " << myints.size() << '\n';
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';
	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

	std::cout << std::endl;
	std::cout << "FT:" << std::endl;
	std::cout << "0. size: " << ft_myints.size() << '\n';
	for (int i=0; i<5; i++) ft_myints.push(i);
	std::cout << "1. size: " << ft_myints.size() << '\n';
	ft_myints.pop();
	std::cout << "2. size: " << ft_myints.size() << '\n';
	return 0;
}