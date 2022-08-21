#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){

	std::vector<int> myvector;
  	int myint;
	ft::vector<int> ft_myvector;
  	//int ft_myint;

  	std::cout << "Please enter some integers (enter 0 to end):\n";

  	do {
    	std::cin >> myint;
    	myvector.push_back (myint);
		ft_myvector.push_back (myint);
  	} while (myint);

  	std::cout << "STD: myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "FT: myvector stores " << int(ft_myvector.size()) << " numbers.\n";

	return 0;
}