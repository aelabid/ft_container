// #include"../includes/vector.hpp"
// #include"../utils/pair.hpp"
// #include"vector_it.hpp"
#include<iostream>
#include "../map/map.hpp"
#include<map>

int main()
{
	map<int, int> m;
  m.insert(ft::make_pair(1, 100));
  m.insert(ft::make_pair(2, 200));
  m.insert(ft::make_pair(0, 200));
  m.insert(ft::make_pair(4, 200));
  m.insert(ft::make_pair(54, 300));
  // map<int, int>::iterator it  = m.begin();
  // map<int, int>::iterator it2  = m.end();
  // // if(it == m.end())
  // ++it;
  // ++it;
  //   std::cout<<(*it).first;
    // --it;
    // std::cout<<it->first;
  //   std::map<int,int> mymap;

  // mymap['b'] = 100;
  // mymap['a'] = 200;
  // mymap['c'] = 300;

  // show content:
  map<int,int>::iterator rit = m.begin();
  // std::map<int,int>::iterator rit = m.begin();
  // rit++;
  // rit--;
  // std::cout<<rit->first;
  for (rit=m.begin(); rit!=m.end(); rit++)
    std::cout << rit->first << " => " << rit->second << '\n';
}
