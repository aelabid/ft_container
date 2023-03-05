#include"../stack/stack.hpp"
#include<stack>
#include<vector>

void stack_test(void)
{
    // -------------------------------STD::Constructors-------------------------------------//
  std::cout<<"---------------constructor test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::vector<int> myvector (2,200);        // vector with 2 elements

    std::stack<int> first;                    // empty stack

    std::stack<int,std::vector<int> > third;  // empty stack using vector
    std::stack<int,std::vector<int> > fourth (myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    std::vector<int> myvector (2,200);        // vector with 2 elements

    ft::stack<int> first;                    // empty stack

    ft::stack<int,std::vector<int> > third;  // empty stack using vector
    ft::stack<int,std::vector<int> > fourth (myvector);

    std::cout << "size of first: " << first.size() << '\n';
    std::cout << "size of third: " << third.size() << '\n';
    std::cout << "size of fourth: " << fourth.size() << '\n';
  }
  std::cout<<"---------------empty test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';
  }
  std::cout<<"---------------size test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';
    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';
    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
  }
  std::cout<<"---------------top test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::stack<int> mystack;
    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::stack<int> mystack;
    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << '\n';
  }
  std::cout<<"---------------push pop test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);
    
    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
  }
  
}