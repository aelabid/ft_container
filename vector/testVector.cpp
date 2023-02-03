#include"../includes/vector.hpp"
#include<vector>
int main()
{
  vector<int> v(6, 20);
  vector<int> d(3, 2);
  vector<int>::iterator it;
  vector<int>:: iterator l;
  vector<int>:: iterator j;
  j=d.begin();
  for(int i =0; i<6; i++)
    v[i] = i+1;
  it = v.begin();
  std::cout<<"this is it\n";
  for(int i =0; i<6; i++)
  {
    std::cout<<*it<<'\t';
    it++;
  }
  it = v.begin();
  l = it + 2;
  l = l + 2;
  std::cout<<"\nthis is l - it\n"<<it-j;
  // for(int k =0; k<2;k++)
  // {
  //   std::cout<<*l<<'\t';
  //   l++;
  // }
  // *it = 10;
  // i = ++it;
  // j = i + 1;
  // *j = 4;
  // std::cout<<*i--;
  // std::cout<<*j++;
  // std::cout<<*j;
  // std::cout<<*it;
  
  // *it =9;
  // for (vector<int>::iterator it)
}
