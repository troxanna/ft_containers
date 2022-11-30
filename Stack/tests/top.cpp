#include <iostream>         

#include <vector>   
#include "../../Vector/vector.hpp"    
#include <stack>   
#include "../Stack.hpp"   

int main(){
	std::stack<int> mystack;
	ft::stack<int> ft_mystack;

	mystack.push(10);
	mystack.push(20);

	ft_mystack.push(10);
	ft_mystack.push(20);

	mystack.top() -= 5;
	ft_mystack.top() -= 5;

	std::cout << "STD: mystack.top() is now " << mystack.top() << '\n';
	std::cout << "FT: mystack.top() is now " << ft_mystack.top() << '\n';

	return 0;
}