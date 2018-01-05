#include "BookItem.hpp"

int BookItem::getSerialNum()
{
    return serialNum;
}

void BookItem::setSerialNum(int serialNum)
{
    this -> serialNum = serialNum;
}

string BookItem::getTitle()
{
    return title;
}

void BookItem::setTitle(string title)
{
    this -> title = title;
}

string BookItem::getAuthor()
{
    return author;
}

void BookItem::setAuthor(string author)
{
    this -> author = author;
}

int BookItem::getYearPublished()
{
    return yearPublished;
}

void BookItem::setYearPublished(int yearPublished)
{
    this -> yearPublished = yearPublished;
}

int BookItem::getCopiesSold()
{
    return copiesSold;
}

void BookItem::setCopiesSold(int copiesSold)
{
    this -> copiesSold = copiesSold;
}

