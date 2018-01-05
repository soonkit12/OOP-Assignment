#ifndef SORTEDLIST_HPP
#define SORTEDLIST_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include "Node.hpp"
#include "BookItem.hpp"
using namespace std;


template <typename T>
class SortedLList{
      Node<T>* start;
      Node<T>* current;

  public:
       SortedLList();
       void sortedinsert(const T& element);
       bool retrieve(int& element);
       bool Delete(int& element);

        friend ostream& operator<< (ostream& os, SortedLList<T>& list)
         {
            os << "start -> ";
            Node<T> *ptr = list.start;
             while (ptr != NULL)
            {
              os << ptr->info << " -> ";
              ptr = ptr->next;
             }
            os << "NULL\n";
            return os;
        }


};


#endif
