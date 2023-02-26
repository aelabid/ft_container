// #include"../includes/vector.hpp"
// #include"../utils/pair.hpp"
// #include"vector_it.hpp"
#include<iostream>
#include <map>
int main()
{
	//---------------------test vectors---------------------//
   std::map<int, int> map;
 
  // Insert some values into the map
  map[1] = 1;
  map[4] = 2;
  map[3] = 3;
 
  // Get an iterator pointing to the first element in the map
  std::map<int, int>::iterator it = map.begin();
  it++;
  it--;
  // Iterate through the map and print the elements
  while (it != map.end())
  {
    std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    ++it;
  }
}

