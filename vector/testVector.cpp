// #include"../includes/vector.hpp"
// #include"../utils/pair.hpp"
// #include"vector_it.hpp"
#include<iostream>
#include "../map/map.hpp"
#include<map>
#include"../includes/vector.hpp"

int main()
{
	ft::map<int, int> m;
  m.insert(ft::make_pair(1, 100));
  m.insert(ft::make_pair(2, 200));
  m.insert(ft::make_pair(0, 200));
  m.insert(ft::make_pair(4, 200));
  m.insert(ft::make_pair(54, 300));
  ft::map<int,int>::reverse_iterator rit=m.rbegin();

  // ++rit;
  // ++rit;
  // ++rit;
  // ++rit;
  //   // std::cout << rit->first << " => " << rit->second << '\n';
  // ++rit;
  // ++rit;
  while(rit != m.rend())
  {
    std::cout << rit->first << " => " << rit->second << '\n';
    // std::cout<<"here";
    ++rit;
  }
  for (rit=m.rbegin(); rit!=m.rend(); ++rit)
    std::cout << rit->first << " => " << rit->second << '\n';

}
