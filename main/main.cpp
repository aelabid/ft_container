#include<iostream>
void vector_test(void);
void stack_test(void);
void    map_test(void);

int main()
{
    int i = 0;
    do{
        std::cout<<"\n\nplease enter 1 || 2 || 3 || 0 to end\n";
        std::cout<<"for vector test => 1\n";
        std::cout<<"for stack  test => 2\n";
        std::cout<<"for map    test => 3\n";
        std::cout<<"0 to end\n";
        std::cin>>i;
        if(i != 0 && i != 1 && i != 2 && i != 3)
            std::cout<<"please enter 1 || 2 || 3 || 0 to end\n";
        else if (i == 0)
            break ;
        else if (i == 1)
            vector_test();
        else if (i == 2)
            stack_test();
        else if (i == 3)
            map_test();
    }while(i);
    return 0;
}