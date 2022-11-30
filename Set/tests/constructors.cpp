#include <iomanip>
#include <iostream>
#include <string>
#include <set>
#include "../Set.hpp"
 
 
int main()
{
  // (1) Default constructor
	std::set<int> stdSet1;
	// std::cout << "stdMap1 something: " << stdMap1["something"] << std::endl;

	stdSet1.insert(3);
	stdSet1.insert(4);
	stdSet1.insert(5);
	stdSet1.insert(3);

	//std::cout << stdSet1
	ft::set<int> ftSet1;
	// std::cout << "ftMap1 something: " << ftMap1["something"] << std::endl;
	ftSet1.insert(3);
	ftSet1.insert(4);
	ftSet1.insert(5);
	ftSet1.insert(3);

	std::cout << "stdSet1 count " << stdSet1.size() << std::endl;
	std::cout << "ftSet1 count " << ftSet1.size() << std::endl;

 
//   // (4) Range constructor
// 	std::map<std::string, int> stdIter(stdMap1.find("anything"), stdMap1.end());
// 	std::cout << "\nstdIter = " << stdIter;
// 	std::cout << "stdMap1 = " << stdMap1;

// 	ft::map<std::string, int> ftIter(ftMap1.find("anything"), ftMap1.end());
// 	std::cout << "\ftIter = " << ftIter;
// 	std::cout << "ftMap1 = " << ftMap1;
 
// //   // (6) Copy constructor
// 	std::map<std::string, int> stdCopied(stdMap1);
// 	std::cout << "\nstdCopied = " << stdCopied;
// 	std::cout << "stdMap1 = " << stdMap1;

// 	ft::map<std::string, int> ftCopied(ftMap1);
// 	std::cout << "\nftCopied = " << ftCopied;
// 	std::cout << "ftMap1 = " << ftMap1;

}