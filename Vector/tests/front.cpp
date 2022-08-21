#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

  	myvector.push_back(78);
  	myvector.push_back(16);

	ft_myvector.push_back(78);
  	ft_myvector.push_back(16);

  // now front equals 78, and back 16

  	myvector.front() -= myvector.back();
	ft_myvector.front() -= ft_myvector.back();

  	std::cout << "STD: myvector.front() is now " << myvector.front() << '\n';
	std::cout << "FT: myvector.front() is now " << ft_myvector.front() << '\n';

	return 0;
}