#include <map>
#include <iterator>
#include <iostream>
#include <utility>
#include <initializer_list>
#include "../map.hpp"
 
void	printStd(std::map<int, int> & stdMap1)
{
	std::cout << "STD: ";
	for (std::map<int, int>::iterator it = stdMap1.begin(); it != stdMap1.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
}

void	printFt(ft::map<int, int> & ftMap1)
{
	std::cout << "FT: ";
	for (ft::map<int, int>::iterator it = ftMap1.begin(); it != ftMap1.end(); it++)
	{
		std::cout << '(' << (it).operator*().first << ':' << (it).operator*().second << ") ";
	}
	std::cout << std::endl;
}

int main()
{
    std::map<int, int> stdX, stdY, stdZ;

	std::cout << "STD:\n";

	stdX.insert(std::make_pair<int, int> (2, 3));
	printStd(stdX);
	stdY = stdX;
	printStd(stdY);
	stdX = stdZ;
	printStd(stdX);
	stdY.insert(std::make_pair<int, int> (4, 4));
	stdZ = stdY;
	printStd(stdZ);
 
	std::cout << "FT:\n";
 	
	ft::map<int, int> ftX, ftY, ftZ;

	ftX.insert(ft::make_pair<int, int> (2, 3));
	printFt(ftX);
	ftY = ftX;
	printFt(ftY);
	ftX = ftZ;
	printFt(ftX);
	ftY.insert(ft::make_pair<int, int> (4, 4));
	ftZ = ftY;
	printFt(ftZ);
    // std::cout << "Initially:\n";
    // print("ftX = ", x);
    // print("y = ", y);
    // print("z = ", z);
 
    // std::cout << "Copy assignment copies data from x to y:\n";
    // y = x;
    // print("x = ", x);
    // print("y = ", y);
 
    // std::cout << "Move assignment moves data from x to z, modifying both x and z:\n";
    // z = std::move(x);
    // print("x = ", x);
    // print("z = ", z);
 
    // std::cout << "Assignment of initializer_list w to z:\n";
    // z = w;
    // print("w = ", w);
    // print("z = ", z);
}