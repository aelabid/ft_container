#include"../vector/vector.hpp"
#include<vector>
int main()
{
  // -------------------------------STD::Constructors-------------------------------------//
  std::cout<<"---------------constructor test---------------\n"<<std::endl;
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
  
  std::cout<<"\n---------------operator=	test---------------\n"<<std::endl;
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
  std::cout<<"\n---------------iterators test---------------\n"<<std::endl;
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

  std::cout<<"\n---------------reverse iterators test---------------\n"<<std::endl;
          // -----------------------std::rbegin rend-----------------------//
          {
            std::vector<int> myvector (5);  // 5 default-constructed ints
            int i=0;
            std::vector<int>::reverse_iterator rit = myvector.rbegin();
            for (; rit!= myvector.rend(); ++rit)
              *rit = ++i;

            std::cout << "myvector contains:";
            for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
              std::cout << ' ' << *it;
            std::cout << '\n';
          }
          std::cout<<"------------ft::test"<<std::endl;
          // -----------------------ft::rbegin rend-----------------------//
          {
            ft::vector<int> myvector (5);  // 5 default-constructed ints
            int i=0;
            ft::vector<int>::reverse_iterator rit = myvector.rbegin();
            for (; rit!= myvector.rend(); ++rit)
              *rit = ++i;

            std::cout << "myvector contains:";
            for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
              std::cout << ' ' << *it;
            std::cout << '\n';
          }

  // -------------------------------STD::capacity-------------------------------------//
  std::cout<<"\n---------------capacity test---------------\n"<<std::endl;
    std::cout<<"------------std::test"<<std::endl;
    {
     // ----------------STD::size------------------//
      std::cout<<"-----std::size\n"<<std::endl;
      std::vector<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';

      for (int i=0; i<10; i++) myints.push_back(i);
      std::cout << "1. size: " << myints.size() << '\n';

      myints.insert (myints.end(),10,100);
      std::cout << "2. size: " << myints.size() << '\n';

      myints.pop_back();
      std::cout << "3. size: " << myints.size() << '\n';
      std::cout << "capacity: " << myints.capacity() << "\n";
      std::cout << "max_size: " << myints.max_size() << "\n";
    }
     // ----------------STD::empty------------------//
    {
      std::cout<<"-----std::empty\n"<<std::endl;
      std::vector<int> myvector;
      int sum (0);

      for (int i=1;i<=10;i++) myvector.push_back(i);

      while (!myvector.empty())
      {
        sum += myvector.back();
        myvector.pop_back();
      }
      std::cout << "total: " << sum << '\n';
    }
    {
      std::cout<<"-----std::resize\n"<<std::endl;
      std::vector<int> myvector;
      for (int i=1;i<10;i++) myvector.push_back(i);

      myvector.resize(5);
      myvector.resize(8,100);
      myvector.resize(12);

      std::cout << "myvector contains:";
      for (int i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';

    }
    {
      std::cout<<"-----std::reserve\n"<<std::endl;
      std::vector<int>::size_type sz;

      std::vector<int> foo;
      sz = foo.capacity();
      std::cout << "making foo grow:\n";
      for (int i=0; i<100; ++i) {
        foo.push_back(i);
        if (sz!=foo.capacity()) {
          sz = foo.capacity();
          std::cout << "capacity changed: " << sz << '\n';
        }
      }

      std::vector<int> bar;
      sz = bar.capacity();
      bar.reserve(100);   // this is the only difference with foo above
      std::cout << "making bar grow:\n";
      for (int i=0; i<100; ++i) {
        bar.push_back(i);
        if (sz!=bar.capacity()) {
          sz = bar.capacity();
          std::cout << "capacity changed: " << sz << '\n';
        }
      }
    }
    std::cout<<"------------ft::test"<<std::endl;
    {
     // ----------------ft::size------------------//
      std::cout<<"-----ft::size\n"<<std::endl;
      ft::vector<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';

      for (int i=0; i<10; i++) myints.push_back(i);
      std::cout << "1. size: " << myints.size() << '\n';

      myints.insert (myints.end(),10,100);
      std::cout << "2. size: " << myints.size() << '\n';

      myints.pop_back();
      std::cout << "3. size: " << myints.size() << '\n';
      std::cout << "capacity: " << myints.capacity() << "\n";
      std::cout << "max_size: " << myints.max_size() << "\n";
    }
    {
      std::cout<<"-----ft::empty\n"<<std::endl;
      ft::vector<int> myvector;
      int sum (0);

      for (int i=1;i<=10;i++) myvector.push_back(i);

      while (!myvector.empty())
      {
        sum += myvector.back();
        myvector.pop_back();
      }
      std::cout << "total: " << sum << '\n';
    }
    {
      std::cout<<"-----ft::resize\n"<<std::endl;
      ft::vector<int> myvector;
      for (int i=1;i<10;i++) myvector.push_back(i);

      myvector.resize(5);
      myvector.resize(8,100);
      myvector.resize(12);

      std::cout << "myvector contains:";
      for (int i=0;i<myvector.size();i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
  //   {
  //   std::cout<<"-----ft::reserve\n"<<std::endl;
  //   ft::vector<int>::size_type sz;

  //   ft::vector<int> foo;
  //   sz = foo.capacity();
  //   std::cout << "making foo grow:\n";
  //   for (int i=0; i<100; ++i) {
  //     foo.push_back(i);
  //     if (sz!=foo.capacity()) {
  //       sz = foo.capacity();
  //       std::cout << "capacity changed: " << sz << '\n';
  //     }
  //   }

  //   ft::vector<int> bar;
  //   sz = bar.capacity();
  //   bar.reserve(100);   // this is the only difference with foo above
  //   std::cout << "making bar grow:\n";
  //   for (int i=0; i<100; ++i) {
  //     bar.push_back(i);
  //     if (sz!=bar.capacity()) {
  //       sz = bar.capacity();
  //       std::cout << "capacity changed: " << sz << '\n';
  //     }
  //   }
  // }


    // -------------------------------STD::element access-------------------------------------//
  std::cout<<"\n---------------element access test---------------\n"<<std::endl;
    std::cout<<"------------std::test"<<std::endl;
    {
      std::cout<<"-------std::front back"<<std::endl;
      std::vector<int> myvector;

      myvector.push_back(78);
      myvector.push_back(16);

      // now front equals 78, and back 16

      myvector.front() -= myvector.back();

      std::cout << "myvector.front() is now " << myvector.front() << '\n';

    }
    {
      std::cout<<"-------std::operator[] std::at"<<std::endl;
      std::vector<int> myvector (10);   // 10 zero-initialized elements

      std::vector<int>::size_type sz = myvector.size();

      // assign some values:
      for (unsigned i=0; i<sz; i++)     myvector.at(i)=i;


      std::cout << "myvector contains:";
      for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    std::cout<<"------------ft::test"<<std::endl;
    {
      std::cout<<"-------ft::front back"<<std::endl;
      ft::vector<int> myvector;

      myvector.push_back(78);
      myvector.push_back(16);

      // now front equals 78, and back 16

      myvector.front() -= myvector.back();

      std::cout << "myvector.front() is now " << myvector.front() << '\n';
    }
    {
      std::cout<<"-------ft::operator[] ft::at"<<std::endl;
      ft::vector<int> myvector (10);   // 10 zero-initialized elements

      ft::vector<int>::size_type sz = myvector.size();

      // assign some values:
      for (unsigned i=0; i<sz; i++)     myvector.at(i)=i;

      
      std::cout << "myvector contains:";
      for (unsigned i=0; i<sz; i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
    }
    // -------------------------------STD::modifiers-------------------------------------//
  std::cout<<"\n---------------modifiers test---------------\n"<<std::endl;
    std::cout<<"------------std::test"<<std::endl;
    {
      std::cout<<"-------std::assign"<<std::endl;
      std::vector<int> first;
      std::vector<int> second;
      std::vector<int> third;

      first.assign (7,100);             // 7 ints with a value of 100

      std::vector<int>::iterator it;
      it=first.begin()+1;

      second.assign (it,first.end()-1); // the 5 central values of first

      int myints[] = {1776,7,4};
      third.assign (myints,myints+3);   // assigning from array.

      std::cout << "Size of first: " << int (first.size()) << '\n';
      std::cout << "Size of second: " << int (second.size()) << '\n';
      std::cout << "Size of third: " << int (third.size()) << '\n';
    }
    std::cout<<"------------ft::test"<<std::endl;
    {
      std::cout<<"-------ft::assign"<<std::endl;
      ft::vector<int> first;
      ft::vector<int> second;
      ft::vector<int> third;

      first.assign (7,100);             // 7 ints with a value of 100

      // ft::vector<int>::iterator it;
      // it=first.begin()+1;

      // second.assign (it,first.end()-1); // the 5 central values of first

      // int myints[] = {1776,7,4};
      // third.assign (myints,myints+3);   // assigning from array.

      std::cout << "Size of first: " << int (first.size()) << '\n';
      std::cout << "Size of second: " << int (second.size()) << '\n';
      std::cout << "Size of third: " << int (third.size()) << '\n';
    }
  return 0;
}
