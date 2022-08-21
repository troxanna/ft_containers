#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

  	// set some content in the vector:
	std::cout << "STD:" << std::endl;
 	for (int i=0; i<100; i++) myvector.push_back(i);
  	std::cout << "size: " << (int) myvector.size() << '\n';
  	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
  	std::cout << "max_size: " << (int) myvector.max_size() << '\n';

	std::cout << std::endl;
	std::cout << "FT:" << std::endl;

	for (int i=0; i<100; i++) ft_myvector.push_back(i);
	std::cout << "size: " << (int) ft_myvector.size() << '\n';
  	std::cout << "capacity: " << (int) ft_myvector.capacity() << '\n';
  	std::cout << "max_size: " << (int) ft_myvector.max_size() << '\n';


	return 0;
}