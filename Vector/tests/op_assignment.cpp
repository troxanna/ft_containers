#include <iostream>         

#include <vector>   
#include "../vector.hpp"  

int main(){
	std::vector<int> foo (3,0);
	std::vector<int> bar (5,0);
	ft::vector<int> ft_foo (3,0);
	ft::vector<int> ft_bar (5,0);

	bar = foo;
	foo = std::vector<int>();
	ft_bar = ft_foo;
	ft_foo = ft::vector<int>();

	std::cout << "STD:" << std::endl;
	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';

	std::cout << "FT:" << std::endl;
	std::cout << "Size of ft_foo: " << int(ft_foo.size()) << '\n';
	std::cout << "Size of ft_bar: " << int(ft_bar.size()) << '\n';
	return 0;
}