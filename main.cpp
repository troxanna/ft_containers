#include <iostream>       // std::cout
#include "Stack.hpp"          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque

int main ()
{
 // std::deque<int> mydeque (3,100);          // deque with 3 elements
  std::vector<int> myvector (2,200);        // vector with 2 elements

  ft::stack<int> first;                    // empty stack
  //ft::stack<int> second (mydeque);         // stack initialized to copy of deque

  ft::stack<int,std::vector<int> > third;  // empty stack using vector
  ft::stack<int,std::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  //std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';



  //size
  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';

  //empty
  ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}