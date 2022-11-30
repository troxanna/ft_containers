#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	ft_myvector.push_back (100);
	ft_myvector.push_back (200);
	ft_myvector.push_back (300);

	
	std::cout << "STD:\n";
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	std::cout << std::endl;
	std::cout << "FT:\n";

	std::cout << "myvector contains:";
	for (unsigned i=0; i<ft_myvector.size(); i++)
		std::cout << ' ' << ft_myvector[i];
	std::cout << '\n';

	ft_myvector.clear();
	ft_myvector.push_back (1101);
	ft_myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<ft_myvector.size(); i++)
		std::cout << ' ' << ft_myvector[i];
	std::cout << '\n';

	return 0;
}