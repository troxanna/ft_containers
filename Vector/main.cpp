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
  arr.reserve(8);
  

  std::cout << arr.capacity() << std::endl;
  std::cout << arr.size() << std::endl;

  for (size_t i = 0; i < 5; i++)
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

  //std::cout << it1 - it2 << std::endl;

  std::vector<int> arr2;
  for (size_t i = 0; i < 5; i++)
  {
    arr2.push_back(i);
  }
  arr2.reserve(3);
  
  //конструтор для константного итератора
  std::vector<int>::iterator it = arr2.begin();
  std::vector<int>::iterator ite = arr2.end();

  //std::cout << it - ite << std::endl;
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


  arr.erase(it1, it1 + 2);
  arr2.erase(it, it + 2);

  std::cout << arr2[1];
  std::cout << arr[1];

  std::cout << std::endl;
  std::cout << std::endl;

  arr.insert(it1 + arr.size() - 1, 44);
  arr2.insert(it + arr.size() - 1, 44);

  std::cout << arr2[arr.size() - 1] << std::endl;
  std::cout << arr[arr.size() - 1];

  return 0;
}