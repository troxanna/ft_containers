#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	ft::vector<int> ft_first;
	ft::vector<int> ft_second;
	ft::vector<int> ft_third;

	first.assign (7,100);    
	ft_first.assign (7,100);          // 7 ints with a value of 100

	std::vector<int>::iterator it;
	it=first.begin()+1;

	ft::vector<int>::iterator ft_it;
	ft_it=ft_first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first
	ft_second.assign (ft_it,ft_first.end()-1);

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.
	int ft_myints[] = {1776,7,4};
	ft_third.assign (ft_myints,ft_myints+3);

	std::cout << "STD:\n";
	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';

	std::cout << std::endl;
	std::cout << "FT:\n";
	std::cout << "Size of first: " << int (ft_first.size()) << '\n';
	std::cout << "Size of second: " << int (ft_second.size()) << '\n';
	std::cout << "Size of third: " << int (ft_third.size()) << '\n';

  	return 0;
}