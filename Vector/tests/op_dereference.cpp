#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> myvector (10);   // 10 zero-initialized elements
	std::vector<int>::size_type sz = myvector.size();

	ft::vector<int> ft_myvector (10);   // 10 zero-initialized elements
	ft::vector<int>::size_type ft_sz = ft_myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;
	for (unsigned i=0; i<ft_sz; i++) ft_myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	for (unsigned i=0; i<ft_sz/2; i++)
	{
		int ft_temp;
		ft_temp = ft_myvector[ft_sz-1-i];
		ft_myvector[ft_sz-1-i]=ft_myvector[i];
		ft_myvector[i]=ft_temp;
	}

	std::cout << "STD: myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	//std::cout << std::endl;
	std::cout << "FT: myvector contains:";
	for (unsigned i=0; i<ft_sz; i++)
		std::cout << ' ' << ft_myvector[i];
	std::cout << '\n';

	return 0;
}