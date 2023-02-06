#include"../includes/vector.hpp"
#include<iostream>
#include<vector>

  // vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
int main()
{
  vector<int> myvector (5,100);
  vector<int> anothervector (2,400);
  vector<int>::iterator it;
  vector<int>::iterator it2;

  it = myvector.begin();
  // it2 = anothervector.begin();
  it = myvector.insert ( it+2  , 200 );
  std::cout << "size------>" << myvector.size() << std::endl;
  it = myvector.insert ( it+1  , 300 );

  // myvector.insert (it+1,2,300);

  // // "it" no longer valid, get a new one:
  it = myvector.begin();

  // myvector.insert (it+2, anothervector.begin(), anothervector.end());

  // // int myarray [] = { 501,502,503 };
  // // myvector.insert (myvector.begin(), myarray, myarray+3);

  // std::cout << "myvector contains: size = "<<myvector.size()<< " capacity = "<<myvector.capacity();
  // for (it=myvector.begin(); it<myvector.end(); it++)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';

  return 0;
}

