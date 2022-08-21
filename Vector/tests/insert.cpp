#include <iostream>         

#include <vector>   
#include "../Vector.hpp"    

int main(){
	std::vector<int> myvector (3,100);
	std::vector<int>::iterator it;
	ft::vector<int> ft_myvector (3,100);
	ft::vector<int>::iterator ft_it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	ft_it = ft_myvector.begin();
	ft_it = ft_myvector.insert ( ft_it , 200 );

	myvector.insert (it,2,300);
	ft_myvector.insert (ft_it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();
	ft_it = ft_myvector.begin();

	std::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	ft::vector<int> ft_anothervector (2,400);
	ft_myvector.insert (ft_it+2,ft_anothervector.begin(),ft_anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);
	int ft_myarray [] = { 501,502,503 };
	ft_myvector.insert (ft_myvector.begin(), ft_myarray, ft_myarray+3);

	std::cout << "STD: myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "FT: myvector contains:";
	for (ft_it=ft_myvector.begin(); ft_it<ft_myvector.end(); ft_it++)
		std::cout << ' ' << *ft_it;
	std::cout << '\n';

	return 0;
}