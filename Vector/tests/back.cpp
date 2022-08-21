#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

	myvector.push_back(10);
	ft_myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	while (ft_myvector.back() != 0)
	{
		ft_myvector.push_back ( ft_myvector.back() -1 );
	}


	std::cout << "STD: myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << "FT: myvector contains:";
	for (unsigned i=0; i<ft_myvector.size() ; i++)
		std::cout << ' ' << ft_myvector[i];
	std::cout << '\n';

	return 0;
}