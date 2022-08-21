#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector;
  	int * p;
  	unsigned int i;
	ft::vector<int> ft_myvector;
  	int * ft_p;
  	unsigned int ft_i;

  	// allocate an array with space for 5 elements using vector's allocator:
  	p = myvector.get_allocator().allocate(5);
	ft_p = ft_myvector.get_allocator().allocate(5);

  	// construct values in-place on the array:
  	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
	for (ft_i=0; ft_i<5; ft_i++) ft_myvector.get_allocator().construct(&ft_p[ft_i],ft_i);

	std::cout << "STD: The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	std::cout << "FT: The allocated array contains:";
	for (ft_i=0; ft_i<5; ft_i++) std::cout << ' ' << ft_p[ft_i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);

	for (ft_i=0; ft_i<5; ft_i++) ft_myvector.get_allocator().destroy(&ft_p[ft_i]);
	ft_myvector.get_allocator().deallocate(ft_p,5);

	return 0;
}