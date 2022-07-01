#include <iostream>       // std::cout
#include "Vector.hpp"          // std::stack
//#include <vector>         // std::vector
#include <deque>          // std::deque
#include <vector>

int main ()
{
 
  //at - проверить, как обрабатывется отрицательное число
  // когда [] или at возвращает ссылку, можем ли мы изменить значение объекта?
  //assign - должны ли мы очищать память и заново выделять или нет?

  ft::vector<int> arr(0);
  const ft::vector<int> arr_const(0);
  ft::vector<const int> const_arr(0);
  //arr.reserve(8);
  

  std::cout << arr.size() << std::endl;

  for (size_t i = 0; i < 4; i++)
  {
      arr.push_back((int)i);
      std::cout << arr.at(i);
      //std::cout << arr.size() << std::endl;
  }
  std::cout << std::endl;
  std::cout << arr.capacity() << std::endl;
  std::cout << arr.size() << std::endl;

  ft::VectorIterator<int> it1 = arr.begin();
  

  ft::VectorIterator<int> it2 = arr.end();

  std::vector<int> arr2;
  for (size_t i = 0; i < 4; i++)
  {
    arr2.push_back(i);
  }
  //arr2.reserve(3);

  //конструтор для константного итератора
  std::vector<int>::iterator it = arr2.begin();
  std::vector<int>::iterator ite = arr2.end();

  // a + b; a - b

  // for (size_t i = 0; i < 3; i++)
  // {
  //   --ite;
  //   --it2;
  // }
  
  // for (size_t i = 0; i < 2; i++)
  // {
  //   std::cout << *(it + i);
  //   std::cout << *(it1 + i) << std::endl;
  //   arr2.erase(it + i);
  //   arr.erase(it1 + i);
  // }
  std::cout << it.operator->() << std::endl;
  std::cout << &(it.operator*()) << std::endl;


  //arr2.insert()
  // arr.erase(it1, it1);
  // arr2.erase(it, it);

  std::cout << arr2[1] << std::endl;
  std::cout << arr[1];

  std::cout << std::endl;
  std::cout << std::endl;


  //arr.reserve(arr.size() + 2);

  ft::vector<int>::iterator it_test = arr.begin();
  std::cout << &(*(it_test)) << "##" << std::endl;
  // std::cout << &(*(it1)) << "---" << std::endl;

  arr.insert(it_test + 1, (size_t)2, 44);
  arr2.insert(it + 1, 2, 44);
  for (size_t i = 0; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  for (size_t i = 0; i < arr2.size(); i++)
  {
    std::cout << arr2[i] <<  " ";
  }
  std::cout << arr2[arr.size() - 1] << std::endl;
  std::cout << arr[arr.size() - 1];

  ft::vector<int> lhs;
  ft::vector<int> rhs;

  for (size_t i = 0; i < 10; i++)
    rhs.push_back((int)i);
  for (size_t i = 0; i < 10; i++)
    lhs.push_back((int)i);

  ft::vector<int>::iterator itLhs = lhs.begin();
  ft::vector<int>::iterator itRhs = rhs.begin();
  std::cout << std::endl;
  lhs.insert(lhs.end() - 3, 2);
  //rhs.insert(itRhs, 2);

  for (size_t i = 0; i < lhs.size(); i++)
    std::cout << lhs[i] << " ";
  std::cout << std::endl;
  for (size_t i = 0; i < rhs.size(); i++)
    std::cout << rhs[i] << " ";

  if (lhs >= rhs)
    std::cout << "lhs";
  else
    std::cout << "rhs";

  // ft::vector<int>::iterator c_it = arr.begin();
  // ft::vector<int>::const_iterator v_it = c_it;



  std::vector<int>::iterator c_it = arr2.begin();
  
  std::vector<int>::const_iterator v_it = c_it;
  
  return 0;
}