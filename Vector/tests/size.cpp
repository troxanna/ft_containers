#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myints;
	ft::vector<int> ft_myints;

	std::cout << "STD:" << std::endl;
	std::cout << "0. size: " << myints.size() << '\n';
	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';
	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';
	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';

	std::cout << std::endl;
	std::cout << "FT:" << std::endl;
	std::cout << "0. size: " << ft_myints.size() << '\n';
	for (int i=0; i<10; i++) ft_myints.push_back(i);
	std::cout << "1. size: " << ft_myints.size() << '\n';
	ft_myints.insert (ft_myints.end(),10,100);
	std::cout << "2. size: " << ft_myints.size() << '\n';
	ft_myints.pop_back();
	std::cout << "3. size: " << ft_myints.size() << '\n';

	return 0;
}