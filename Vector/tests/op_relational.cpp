#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> foo (3,100);   // three ints with a value of 100
  	std::vector<int> bar (2,200);   // two ints with a value of 200
	ft::vector<int> ft_foo (3,100);
	ft::vector<int> ft_bar (2,200);

	std::cout << "STD:\n";
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout <<std::endl;
	std::cout << "FT:\n";
	if (ft_foo==ft_bar) std::cout << "foo and bar are equal\n";
	if (ft_foo!=ft_bar) std::cout << "foo and bar are not equal\n";
	if (ft_foo< ft_bar) std::cout << "foo is less than bar\n";
	if (ft_foo> ft_bar) std::cout << "foo is greater than bar\n";
	if (ft_foo<=ft_bar) std::cout << "foo is less than or equal to bar\n";
	if (ft_foo>=ft_bar) std::cout << "foo is greater than or equal to bar\n";

	return 0;
}