#ifndef SORTING_HPP
#define SORTING_HPP
#include <iostream>
#include <vector>
#include <algorithm>


class SortByTitle
{
public:
    bool operator()(BookItem b1, BookItem b2)
    {
        return b1.getTitle() > b2.getTitle();
    }
};

#endif
