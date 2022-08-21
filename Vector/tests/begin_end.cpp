#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=5; i++) ft_myvector.push_back(i);

	std::cout << "STD: myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "FT: myvector contains:";
	for (ft::vector<int>::iterator it = ft_myvector.begin() ; it != ft_myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}