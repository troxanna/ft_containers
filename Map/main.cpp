#include <iostream>       // std::cout
#include "Map.hpp"          // std::stack
#include <map>  
//#include <vector>         // std::vector
#include <deque>          // std::deque
#include <vector>

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};


int main ()
{
 
  //at - проверить, как обрабатывется отрицательное число
  // когда [] или at возвращает ссылку, можем ли мы изменить значение объекта?
  //assign - должны ли мы очищать память и заново выделять или нет?

  //ft::map<int> arr(0);
	std::map<char,int> first;
	ft::map<char,int> ft_first;
  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

	ft_first['a']=10;
  ft_first['b']=30;
  ft_first['c']=50;
  ft_first['d']=70;

  std::map<char,int> second (first.begin(),first.end());

  std::map<char,int> third (second);

  std::map<char,int,classcomp> fourth;

// ft::map<char,int> ft_second (ft_first.begin(), ft_first.end());

//   ft::map<char,int> ft_third (ft_second);

//   ft::map<char,int,classcomp> ft_fourth;

  bool(*fn_pt)(char,char) = fncomp;
  std::map<char,int,bool(*)(char,char)> fifth (fn_pt); 

//    bool(*ft_fn_pt)(char,char) = fncomp;
//   ft::map<char,int,bool(*)(char,char)> ft_fifth (ft_fn_pt); 
  
  return 0;
}