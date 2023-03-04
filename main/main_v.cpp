#include"../vector/vector.hpp"
#include<vector>
int main()
{
  // -------------------------------STD::Constructors-------------------------------------//
  std::cout<<"---------------constructor test---------------"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::vector<int> first;                              
    std::vector<int> second (4,100);                     
    std::vector<int> third (second.begin(),second.end());
    std::vector<int> fourth (third);                     

    std::cout << "The contents of second are:";
    for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "The contents of third are:";
    for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "The contents of fourth are:";
    for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }
  // -------------------------------FT::Constructors-------------------------------------//
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::vector<int> first;                              
    ft::vector<int> second (4,100);                     
    ft::vector<int> third (second.begin(),second.end());
    ft::vector<int> fourth (third);                     

    std::cout << "The contents of second are:";
    for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "The contents of third are:";
    for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "The contents of fourth are:";
    for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';
  }

  // -------------------------------STD::operator=-------------------------------------//
  
  std::cout<<"---------------operator=	test---------------"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::vector<int> foo (3,0);
    std::vector<int> bar (5,0);

    bar = foo;
    foo = std::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
  }
  // -------------------------------FT::operator=-------------------------------------//
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::vector<int> foo (3,0);
    ft::vector<int> bar (5,0);

    bar = foo;
    foo = ft::vector<int>();

    std::cout << "Size of foo: " << int(foo.size()) << '\n';
    std::cout << "Size of bar: " << int(bar.size()) << '\n';
  }


  // -------------------------------STD::iterators-------------------------------------//
  std::cout<<"---------------iterators test---------------"<<std::endl;
          // -----------------------STD::begin end-----------------------//
        {
          std::cout<<"------------std::test"<<std::endl;
          std::vector<int> myvector;
          for (int i=1; i<=5; i++) myvector.push_back(i);

          std::cout << "myvector contains:";
          for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            std::cout << ' ' << *it;
          std::cout << '\n';
        }
          // -----------------------FT::begin end-----------------------//
        {
          std::cout<<"------------ft::test"<<std::endl;
          ft::vector<int> myvector;
          for (int i=1; i<=5; i++) myvector.push_back(i);

          std::cout << "myvector contains:";
          for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            std::cout << ' ' << *it;
          std::cout << '\n';
        }

  std::cout<<"---------------reverse iterators test---------------"<<std::endl;
          std::cout<<"------------std::test"<<std::endl;
          // -----------------------std::rbegin rend-----------------------//
          {
            std::vector<int> myvector (5);  // 5 default-constructed ints
            // int i=0;
            // std::vector<int>::reverse_iterator rit = myvector.rbegin();
            // for (; rit!= myvector.rend(); ++rit)
            //   *rit = ++i;

            std::cout << "myvector contains:";
            for (std::vector<int>::reverse_iterator it = myvector.rend(); it != myvector.rbegin(); --it)
              std::cout << ' ' << *it;
            std::cout << '\n';
          }
          std::cout<<"------------ft::test"<<std::endl;
          // -----------------------ft::rbegin rend-----------------------//
          {
            // ft::vector<int> myvector (5);  // 5 default-constructed ints
            // int i=0;
            // // std::vector<int>::reverse_iterator rit = myvector.rbegin();
            // // for (; rit!= myvector.rend(); ++rit)
            // //   *rit = ++i;

            // std::cout << "myvector contains:";
            // for (ft::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
            //   std::cout << ' ' << *it;
            // std::cout << '\n';
          }
  return 0;
}
