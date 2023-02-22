// // #include"../includes/vector.hpp"
// // #include"../utils/pair.hpp"
// // #include"vector_it.hpp"
// // int main()
// // {
// // 	//---------------------test vectors---------------------//
// //     vector<int> v(5 , 10);
// //     for(vector<int>::iterator it = v.begin(); it < v.end(); *it++)
// //         std::cout<<*it<<" ";
// // 	int n = 1;
// //     int a[5] = {1, 2, 3, 4, 5};
 
// //     // build a pair from two ints
// //     pair<int, int*> p1 = make_pair(n, a+ 1);
// //     std::cout << "The value of p1 is "
// //               << "(" << p1.first << ", " << *(p1.second + 1) << ")\n";
// // 	std::cout<<p1.first;
// // 	// std::cout<<~int();
// // }

// #include <iostream>
// #include <map>

// struct MyComparison {
//   bool operator()(const int& a, const int& b) const {
//     return a < b;
//   }
// };
// int main ()
// {
//   std::map<char,int> first;

//   first['a']=10;
//   first['k']=10;
//   first['b']=30;
//   first['c']=50;
//   first['k']=70;

//   std::map<char,int> second (first.begin(),first.end());
//   std::map<char, int>::iterator it;
//   std::map<char,int> third (second);

//   std::map<char,int,MyComparison> fourth;                 // class as Compare

//   // bool(*fn_pt)(char,char) = fncomp;
//   // std::map<char,int,bool(*)(char,char)> fifth (fn_pt);
//   std::map<char, int>::iterator it2;
//    // function pointer as Compare 
//   // it2 = fifth.begin();
//   // for(it = first.begin(); it != first.end(); it++)
//   // {
//   //   it2 = it;
//   // }
//   fourth['a']=10;
//   fourth['k']=10;
//   fourth['b']=30;
//   fourth['c']=50;
//   fourth['k']=70;
//   // fifth = first;
//   for(it = fourth.begin(); it != fourth.end(); it++)
//     std::cout<< it->first  << " " << it->second<< " ";

//   return 0;
// }
#include <iostream>
#include <map>
#include"../map/map.hpp"
int main ()
{
  std::map<char,int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['a']=3003;

  std::cout << "mymap contains:\n";

  // std::pair<char,int> highest = *mymap.rbegin();          // last element
  
  std::map<char,int>::reverse_iterator highest = mymap.rbegin();
  std::map<char,int>::iterator it = mymap.begin();
  do {
    std::cout << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, *highest) );

  return 0;
}