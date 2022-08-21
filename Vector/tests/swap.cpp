#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> foo (3,100);   // three ints with a value of 100
  	std::vector<int> bar (5,200);   // five ints with a value of 200
	ft::vector<int> ft_foo (3,100); 
	ft::vector<int> ft_bar (5,200); 

	foo.swap(bar);
	ft_foo.swap(ft_bar);

	std::cout << "STD:\n";

  	std::cout << "foo contains:";
  	for (unsigned i=0; i<foo.size(); i++)
    	std::cout << ' ' << foo[i];
  	std::cout << '\n';

  	std::cout << "bar contains:";
  	for (unsigned i=0; i<bar.size(); i++)
    	std::cout << ' ' << bar[i];
  	std::cout << '\n';

	std::cout << std::endl;
	std::cout << "FT:\n";

	std::cout << "foo contains:";
  	for (unsigned i=0; i<ft_foo.size(); i++)
    	std::cout << ' ' << ft_foo[i];
  	std::cout << '\n';

  	std::cout << "bar contains:";
  	for (unsigned i=0; i<ft_bar.size(); i++)
    	std::cout << ' ' << ft_bar[i];
  	std::cout << '\n';
	  

	return 0;
}