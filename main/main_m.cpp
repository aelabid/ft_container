#include<map>
#include"../map/map.hpp"

void    map_test(void)
{
    // -------------------------------STD::Constructors-------------------------------------//
  std::cout<<"---------------constructor test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    std::map<char,int> second (first.begin(),first.end());

    std::map<char,int> third (second);
    std::map<char,int>::iterator it;
    std::cout<<"first map =>\n";
    for(it= first.begin(); it != first.end(); it++)
        std::cout<<it->first<<" => "<<it->second<<" ";
    std::cout<<"\n";
    std::cout<<"second map =>\n";
    for(it= second.begin(); it != second.end(); it++)
        std::cout<<it->first<<" => "<<it->second<<" ";
    std::cout<<"\n";
    std::cout<<"third map =>\n";
    for(it= third.begin(); it != third.end(); it++)
        std::cout<<it->first<<" => "<<it->second<<" ";
    std::cout<<"\n";
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> first;

    first['a']=10;
    first['b']=30;
    first['c']=50;
    first['d']=70;

    ft::map<char,int> second (first.begin(),first.end());

    ft::map<char,int> third (second);
    ft::map<char,int>::iterator it;
    std::cout<<"first map =>\n";
    for(it= first.begin(); it != first.end(); it++)
        std::cout<<it->first<<" => "<<it->second<<" ";
    std::cout<<"\n";
    std::cout<<"second map =>\n";
    for(it= second.begin(); it != second.end(); it++)
        std::cout<<it->first<<" => "<<it->second<<" ";
    std::cout<<"\n";
    std::cout<<"third map =>\n";
    for(it= third.begin(); it != third.end(); it++)
        std::cout<<it->first<<" => "<<it->second<<" ";
    std::cout<<"\n";
  }
   std::cout<<"---------------operator= test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> first;
    std::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;

    second=first;                // second now contains 3 ints

    std::cout << "Size of first: " << first.size() << '\n';
    std::cout << "Size of second: " << second.size() << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> first;
    ft::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;

    second=first;                // second now contains 3 ints

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
  }
  std::cout<<"---------------begin end test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
    std::cout<<"---------------rbegin rend test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (std::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (ft::map<char,int>::reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
    std::cout<<"---------------size test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;
    mymap['a']=101;
    mymap['b']=202;
    mymap['c']=302;

    std::cout << "mymap.size() is " << mymap.size() << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;
    mymap['a']=101;
    mymap['b']=202;
    mymap['c']=302;

    std::cout << "mymap.size() is " << mymap.size() << '\n';
  }
  std::cout<<"---------------max_size test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    int i;
    std::map<int,int> mymap;

    if (mymap.max_size()>1000)
    {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";

  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    int i;
    ft::map<int,int> mymap;

    if (mymap.max_size()>1000)
    {
        for (i=0; i<1000; i++) mymap[i]=0;
        std::cout << "The map contains 1000 elements.\n";
    }
    else std::cout << "The map could not hold 1000 elements.\n";

  }
  std::cout<<"---------------empty erase  test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;

    while (!mymap.empty())
    {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
    }
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    while (!mymap.empty())
    {
        std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
        mymap.erase(mymap.begin());
    }
  }
  std::cout<<"---------------operator[] test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,std::string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,std::string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
  }
  std::cout<<"---------------insert test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( std::pair<char,int>('a',100) );
    mymap.insert ( std::pair<char,int>('z',200) );

    std::pair<std::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( std::pair<char,int>('z',500) );
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    std::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

    // third insert function version (range insertion):
    std::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

    // showing contents:
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;

    // first insert function version (single parameter):
    mymap.insert ( ft::pair<char,int>('a',100) );
    mymap.insert ( ft::pair<char,int>('z',200) );

    ft::pair<ft::map<char,int>::iterator,bool> ret;
    ret = mymap.insert ( ft::pair<char,int>('z',500) );
    if (ret.second==false) {
        std::cout << "element 'z' already existed";
        std::cout << " with a value of " << ret.first->second << '\n';
    }

    // second insert function version (with hint position):
    ft::map<char,int>::iterator it = mymap.begin();
    mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

    // third insert function version (range insertion):
    ft::map<char,int> anothermap;
    anothermap.insert(mymap.begin(),mymap.find('c'));

    // showing contents:
    std::cout << "mymap contains:\n";
    for (it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "anothermap contains:\n";
    for (it=anothermap.begin(); it!=anothermap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
  std::cout<<"---------------clear test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;

    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;

    std::cout << "mymap contains:\n";
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;

    std::cout << "mymap contains:\n";
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;

    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;

    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;

    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
  }
  std::cout<<"---------------count test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c)>0)
        std::cout << " is an element of mymap.\n";
        else 
        std::cout << " is not an element of mymap.\n";
    }
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;
    char c;

    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;

    for (c='a'; c<'h'; c++)
    {
        std::cout << c;
        if (mymap.count(c)>0)
        std::cout << " is an element of mymap.\n";
        else 
        std::cout << " is not an element of mymap.\n";
    }
  }
  std::cout<<"---------------find test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;
    std::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator it;

    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;

    it = mymap.find('b');
    if (it != mymap.end())
        mymap.erase (it);

    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
  }
  std::cout<<"---------------lowerUpper_bound test---------------\n"<<std::endl;
  {
    std::cout<<"------------std::test"<<std::endl;
    std::map<char,int> mymap;
    std::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)
    std::cout<<"lower bound = "<< itlow->first<<"\n";
    std::cout<<"uper bound = "<< itup->first<<"\n"; 
  }
  {
    std::cout<<"------------ft::test"<<std::endl;
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)
    std::cout<<"lower bound = "<< itlow->first<<"\n";
    std::cout<<"upper bound = "<< itup->first<<"\n";
  }
}