#include <iostream>         

#include <vector>   
#include "../../Vector/Vector.hpp"    
#include <stack>   
#include "../Stack.hpp"   

int main(){
	std::stack<int> mystack;
  	int sum (0);
	ft::stack<int> ft_mystack;
  	int ft_sum (0);

  	for (int i=1;i<=10;i++) mystack.push(i);
	for (int i=1;i<=10;i++) ft_mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	while (!ft_mystack.empty())
	{
		ft_sum += ft_mystack.top();
		ft_mystack.pop();
	}

  	std::cout << "STD: total: " << sum << '\n';
	std::cout << "FT: total: " << ft_sum << '\n';
	return 0;
}