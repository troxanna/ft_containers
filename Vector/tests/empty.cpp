#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;
  	int sum (0);
	int ft_sum (0);

  	for (int i=1;i<=10;i++) myvector.push_back(i);
	for (int i=1;i<=10;i++) ft_myvector.push_back(i);

  	while (!myvector.empty())
  	{
    	sum += myvector.back();
    	myvector.pop_back();
  	}

	while (!ft_myvector.empty())
  	{
    	ft_sum += ft_myvector.back();
    	ft_myvector.pop_back();
  	}

	std::cout << "STD: total: " << sum << '\n';
	std::cout << "FT: total: " << ft_sum << '\n';

	return 0;
}