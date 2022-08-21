#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	// constructors used in the same order as described above:
	/*vector*/
	std::vector<int> first;                                // empty vector of ints
	std::vector<int> second (4,100);                       // four ints with value 100
	std::vector<int> third (second.begin(),second.end());  // iterating through second
	std::vector<int> fourth (third);                       // a copy of third

	/*ft_vector*/
	ft::vector<int> ft_first;                                // empty vector of ints
	ft::vector<int> ft_second (4,100);                       // four ints with value 100
	ft::vector<int> ft_third (ft_second.begin(),ft_second.end());  // iterating through second
	ft::vector<int> ft_fourth (ft_third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	/*vector*/
	int myints[] = {16,2,77,29};
	std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	/*ft_vector*/
	int ft_myints[] = {16,2,77,29};
	ft::vector<int> ft_fifth (ft_myints, ft_myints + sizeof(ft_myints) / sizeof(int) );

	/*vector*/
	std::cout << "STD: The contents of fifth are:";
	for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	/*ft_vector*/
	std::cout << "FT: The contents of fifth are:";
	for (ft::vector<int>::iterator it = ft_fifth.begin(); it != ft_fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


	return 0;
}