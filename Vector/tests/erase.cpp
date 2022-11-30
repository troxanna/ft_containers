#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

  	// set some values (from 1 to 10)
  	for (int i=1; i<=10; i++) myvector.push_back(i);
	for (int i=1; i<=10; i++) ft_myvector.push_back(i);

  	// erase the 6th element
  	myvector.erase (myvector.begin()+5);
	ft_myvector.erase (ft_myvector.begin()+5);

  	// erase the first 3 elements:
  	myvector.erase (myvector.begin(),myvector.begin()+3);
	ft_myvector.erase (ft_myvector.begin(), ft_myvector.begin()+3);

  	std::cout << "STD: myvector contains:";
  	for (unsigned i=0; i<myvector.size(); ++i)
    	std::cout << ' ' << myvector[i];
  	std::cout << '\n';

	std::cout << "FT: myvector contains:";
  	for (unsigned i=0; i<ft_myvector.size(); ++i)
    	std::cout << ' ' << ft_myvector[i];
  	std::cout << '\n';

	return 0;
}