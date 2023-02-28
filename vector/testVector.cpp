// #include"../includes/vector.hpp"
// #include"../utils/pair.hpp"
// #include"vector_it.hpp"
#include<iostream>
#include "../map/map.hpp"
#include<map>

int main()
{
	map<int, int> m;
  m.insert(ft::make_pair(10, 15));
  m.insert(ft::make_pair(20, 15));
  m.insert(ft::make_pair(30, 15));
  map<int, int>::iterator it  = m.begin();
  // map<int, int>::iterator it2  = m.begin();
  if(it == m.begin())
    std::cout<<(*it).first;
    --it;
}
