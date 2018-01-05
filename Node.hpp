#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

using namespace std;

template <typename T>
struct Node
{
   T info;
   Node<T>* next;
};

#endif
