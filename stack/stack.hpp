#pragma once
#include"../vector/vector.hpp"
namespace ft {

template <class T, class Container = ft::vector<T> >
class stack
{
    public:
    typedef T                                           value_type;
    typedef Container                                   container_type;
    typedef size_t                                      size_type;
    explicit stack (const container_type& ctnr = container_type())
    {
        _stack = ctnr;
    };
    bool empty() const
    {
        return _stack.empty();
    };
    size_type size() const
    {
        return _stack.size();
    };
    value_type& top()
    {
        return _stack.back();
    };
    const value_type& top() const
    {
        return _stack.back();
    };
    void push (const value_type& val)
    {
        _stack.push_back(val);
    };
    void pop()
    {
        _stack.pop_back();
    };

    private:
        container_type _stack;
};
}