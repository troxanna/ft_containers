#include <iostream>         

#include <vector>   
#include "../vector.hpp"    

int main(){

	std::cout << "STD:\n";

	std::vector<int>::size_type sz;

	std::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
		sz = foo.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
		sz = bar.capacity();
		std::cout << "capacity changed: " << sz << '\n';
		}
	}

	std::cout << std::endl;
	std::cout << "FT:\n";

	ft::vector<int>::size_type ft_sz;

	ft::vector<int> ft_foo;
	ft_sz = ft_foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		ft_foo.push_back(i);
		if (ft_sz!=ft_foo.capacity()) {
			ft_sz = ft_foo.capacity();
			std::cout << "capacity changed: " << ft_sz << '\n';
		}
	}

	ft::vector<int> ft_bar;
	ft_sz = ft_bar.capacity();
	ft_bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		ft_bar.push_back(i);
		if (ft_sz!=ft_bar.capacity()) {
			ft_sz = ft_bar.capacity();
			std::cout << "capacity changed: " << ft_sz << '\n';
		}
	}

	return 0;
}