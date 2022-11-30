#include <iostream>         

#include <vector>   
#include "../../Vector/vector.hpp"    
#include <stack>   
#include "../Stack.hpp"   

int main(){
	std::vector<int> myvector (2,200);        // vector with 2 elements
	ft::vector<int> ft_myvector (2,200); 

	std::stack<int> first;                    // empty stack
	ft::stack<int> ft_first;  

	std::stack<int,std::vector<int> > third;  // empty stack using vector
	std::stack<int,std::vector<int> > fourth (myvector);
	ft::stack<int,ft::vector<int> > ft_third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > ft_fourth (ft_myvector);

	std::cout << "STD:" << std::endl;
	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	std::cout << std::endl;
	std::cout << "FT:" << std::endl;
	std::cout << "size of first: " << ft_first.size() << '\n';
	std::cout << "size of third: " << ft_third.size() << '\n';
	std::cout << "size of fourth: " << ft_fourth.size() << '\n';
	return 0;
}