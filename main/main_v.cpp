// #include"../includes/vector.hpp"
// #include"../utils/pair.hpp"
// #include"vector_it.hpp"
#include<iostream>
#include "../map/map.hpp"
#include<map>
#include"../vector/vector.hpp"

int main()
{
  ft::map<int,int> mymap;
  ft::map<int,int>::iterator itlow,itup;

  mymap[-20]=20;
  mymap[2]=40;
  // mymap[6]=60;
  mymap[9]=80;
  mymap[10]=100;
  mymap[15]=100;
  // it = mymap.begin();
  // itlow=mymap.lower_bound(2);  // itlow points to b
  itup=mymap.upper_bound (6);   // itup points to e (not d!)
  std::cout<<"low = "<<itup->first;
  // std::cout<<"low = "<<itup->first;
  // mymap.erase(itlow,itup);        // erases [itlow,itup)
}
