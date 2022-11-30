#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> myvector (5);  // 5 default-constructed ints
	ft::vector<int> ft_myvector (5); 

	int i=0;
	
	std::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	i = 0;
	ft::vector<int>::reverse_iterator ft_rit = ft_myvector.rbegin();
	for (; ft_rit!= ft_myvector.rend(); ++ft_rit)
		*ft_rit = ++i;

	std::cout << "STD: myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "FT: myvector contains:";
	for (ft::vector<int>::iterator it = ft_myvector.begin(); it != ft_myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}