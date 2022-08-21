#include <iostream>         

#include <vector>   
#include "../../Vector/Vector.hpp"    
#include <stack>   
#include "../Stack.hpp"   

int main(){
	std::stack<int> mystack;
	ft::stack<int> ft_mystack;

	for (int i=0; i<5; ++i) mystack.push(i);
	for (int i=0; i<5; ++i) ft_mystack.push(i);

	std::cout << "STD: Popping out elements...";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';

	std::cout << "FT: Popping out elements...";
	while (!ft_mystack.empty())
	{
		std::cout << ' ' << ft_mystack.top();
		ft_mystack.pop();
	}
	std::cout << '\n';

	return 0;
}