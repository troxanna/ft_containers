#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;
	int sum (0);
	int ft_sum (0);

	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	ft_myvector.push_back (100);
	ft_myvector.push_back (200);
	ft_myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	while (!ft_myvector.empty())
	{
		ft_sum+=ft_myvector.back();
		ft_myvector.pop_back();
	}

  	std::cout << "STD: The elements of myvector add up to " << sum << '\n';
	std::cout << "FT: The elements of myvector add up to " << ft_sum << '\n';

	return 0;
}