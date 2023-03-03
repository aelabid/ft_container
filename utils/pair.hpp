#pragma once
#include<iostream>

namespace ft {

template <class T1, class T2>
    struct pair
    {
        
        typedef T1  first_type;
        typedef T2  second_type;

        first_type  first;
        second_type second;
        
        pair() : first(T1()), second(T2()){};
        template <class U, class V>
        pair(const pair<U, V>& pr) : first(pr.first), second(pr.second){};
        pair(const first_type& a, const second_type& b) : first(a), second(b){};

    };
template< class T1, class T2, class U1, class U2 >
bool operator==( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
{
    return((lhs.first == rhs.first) && (lhs.second == rhs.second));
};
template< class T1, class T2, class U1, class U2 >
bool operator!=( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
{
    return (!(lhs == rhs));
};
template< class T1, class T2, class U1, class U2 >
bool operator<( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
{
    return(lhs.first < rhs.first || (lhs.second < rhs.second && lhs.first<=rhs.first));
};
template< class T1, class T2, class U1, class U2 >
bool operator<=( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
{
    return(!(rhs < lhs));
};
template< class T1, class T2, class U1, class U2 >
bool operator>( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
{
    return(rhs < lhs);
};
template< class T1, class T2, class U1, class U2 >
bool operator>=( const pair<T1, T2>& lhs, const pair<U1, U2>& rhs )
{
    return(!(lhs < rhs));
};

template< class T1, class T2 >
pair<T1, T2> make_pair( T1 t, T2 u )
{
    return pair<T1, T2>(t, u);
};
}