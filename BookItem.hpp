#ifndef BOOKITEM_HPP
#define BOOKITEM_HPP
#include <iostream>
#include <string>
using namespace std;


class BookItem
{
    int serialNum;
    string title;
    string author;
    int yearPublished;
    int copiesSold;
    public:
    BookItem(int serialNum=0, string title="", string ath="", int year=0, int copiesSold=0)
    : serialNum(serialNum), title(title), author(ath), yearPublished(year), copiesSold(copiesSold) {}

    int getSerialNum();
    void setSerialNum(int serialNum);
    string getTitle();
    void setTitle(string title);
    string getAuthor();
    void setAuthor(string author);
    int getYearPublished();
    void setYearPublished(int yearPublished);
    int getCopiesSold();
    void setCopiesSold(int copiesSold);

	friend std::ostream& operator<<(std::ostream& os, const BookItem& s);
    friend bool operator >(BookItem& s1, BookItem& s2);
};

#endif // BOOKITEM_HPP
