#include"../includes/vector.hpp"
#include<vector>
int main()
{
  std::vector<int> v(6, 20);
  std::vector<int>::iterator it;
  std::vector<int>:: iterator i;
  std::vector<int>:: iterator j;
  it = v.begin();
  *it = 10;
  // std::cout<<*it;
  // it++;
  i = ++it;
  j = i -1;
  std::cout << v[it + 2] << std::endl;
  // std::cout<<*i--;
  // std::cout<<*j++;
  // std::cout<<*j;
  // std::cout<<*it;
  
  // *it =9;
  // for (vector<int>::iterator it)
}
