#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

  	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

  	myvector.resize(5);
  	myvector.resize(8,100);
  	myvector.resize(12);

	for (int i=1;i<10;i++) ft_myvector.push_back(i);

  	ft_myvector.resize(5);
  	ft_myvector.resize(8,100);
  	ft_myvector.resize(12);

  	std::cout << "STD: myvector contains:";
  	for (int i=0;i<myvector.size();i++)
    	std::cout << ' ' << myvector[i];
  	std::cout << '\n';

	std::cout << "FT: myvector contains:";
  	for (int i=0;i<ft_myvector.size();i++)
    	std::cout << ' ' << ft_myvector[i];
  	std::cout << '\n';

  	return 0;
}