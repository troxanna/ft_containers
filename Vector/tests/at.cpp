#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector (10);   // 10 zero-initialized ints
	ft::vector<int> ft_myvector (10);   // 10 zero-initialized ints

  // assign some values:
  	for (unsigned i=0; i<myvector.size(); i++)
    	myvector.at(i)=i;

	for (unsigned i=0; i<ft_myvector.size(); i++)
    	ft_myvector.at(i)=i;

  	std::cout << "STD: myvector contains:";
  	for (unsigned i=0; i<myvector.size(); i++)
    	std::cout << ' ' << myvector.at(i);
  	std::cout << '\n';

	std::cout << "FT: myvector contains:";
  	for (unsigned i=0; i<ft_myvector.size(); i++)
    	std::cout << ' ' << ft_myvector.at(i);
  	std::cout << '\n';
	return 0;
}