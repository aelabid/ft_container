#pragma once
#include<iostream>
namespace ft {

template <bool Cond, class T = void>
struct enable_if
{
    typedef T type;
};

template<class T> struct enable_if<false, T> { };
}