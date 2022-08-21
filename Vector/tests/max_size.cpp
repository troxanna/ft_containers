#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

	std::cout << "STD:" << std::endl;
	for (int i=0; i<100; i++) myvector.push_back(i);

  	std::cout << "size: " << myvector.size() << "\n";
  	std::cout << "capacity: " << myvector.capacity() << "\n";
  	std::cout << "max_size: " << myvector.max_size() << "\n";

	std::cout << std::endl;
	std::cout << "FT:" << std::endl;
	for (int i=0; i<100; i++) ft_myvector.push_back(i);

  	std::cout << "size: " << ft_myvector.size() << "\n";
  	std::cout << "capacity: " << ft_myvector.capacity() << "\n";
  	std::cout << "max_size: " << ft_myvector.max_size() << "\n";


	return 0;
}