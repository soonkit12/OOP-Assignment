#ifndef MAIN_CPP
#define MAIN_CPP
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "BookItem.hpp"
#include "sortedlist.hpp"

using namespace std;


void readData(const char* filename, SortedLList<BookItem>*&stBooks,vector<BookItem>& booklist,vector<string> &title,vector<int> &copiesSold) {
    string line;
    ifstream ifs(filename);
    if (ifs.is_open()) {
        cout << "Reading data...\n";
        int c = 0;
        while ( getline (ifs,line) && (*line.c_str() != '\0') )  {
            string delimiter = ",";
            size_t pos = 0;
            string* token = new string[5];
            int f = -1;
            while ((pos = line.find(delimiter)) != string::npos) {
                token[++f] = line.substr(0, pos);
                cout << " " << token[f] << " | " ;
                line.erase(0, pos + delimiter.length());
            }
            token[++f] = line;
            cout << token[f] << endl;       // last item in string
            c++;

            // push to vector (numerical data converted to int)
            BookItem b(atoi(token[0].c_str()), token[1], token[2], atoi(token[3].c_str()), atoi(token[4].c_str()));
            stBooks->sortedinsert(b);
            booklist.push_back(b);
            title.push_back(token[1]);
            copiesSold.push_back(atoi(token[4].c_str()));
        }
        cout << c << " row(s) read." << endl;
        ifs.close();
    }
    else
        cout << "Unable to open file";
}


ostream& operator<<(ostream& os, const BookItem& s)
{
    os << "<" << s.serialNum << "> " << s.title << " : "
       << s.author << " (" << s.yearPublished << ") - "
       << s.copiesSold << " copies sold";
    return os;
}


bool operator >(BookItem& s1, BookItem& s2)
{
    return s1.getTitle() > s2.getTitle();
}


void sllist()
{

    SortedLList<int>slist;
    int choice,num;

    while(true)
    {
        cout << " =====================================" << endl;
        cout << slist << endl;
        cout << "======================================" << endl;
        cout << "        Sorted Linked List               " << endl;
        cout << "====================================== " << endl;
        cout << "    (1)  Sorted insert    " << endl;
        cout << "      (2)  Retrieve     " << endl;
        cout << "      (3)  Delete       " << endl;
        cout << "      (4)  Exit          " << endl << endl;
        cout << " Enter your choice :     " << endl;
        cin >> choice;
        system("CLS");

        switch(choice)
        {
            case 1 :
            {
                 while(true)
                {
                   cout << slist << endl;
                   cout << "Enter a number : ";
                   cin >> num;
                   system("CLS");
                  if(num < 0)
                  {
                     cout << "Invalid number" << endl;
                     system("CLS");
                  }
                  else
                 {
                    break;
                 }
                }
                 slist.sortedinsert(num);
                 break;
            }

//            case 2 :
  //          {
    //            while(true)
      //          {
        //            cout << slist << endl;
          //         cout << "Enter a number : ";
            //       cin >> num;
              //     system("CLS");
                //  if(num < 0)
                  //{
                    // cout << "Invalid number" << endl;
                     //system("CLS");
                  //}
                  //else
                 //{
                  //  break;
                 //}
                //}
                //slist.retrieve(num);
                //break;
            //}

            case 3 :
            {
               while(true)
              {
                  cout << slist << endl;
                  cout << "Enter number to delete : ";
                  cin >> num;
                  if(num < 0)
                  {
                   cout << "Invalid number" << endl;
                   system("CLS");
                   }
                  else
                  {
                       break;
                  }
               }
                slist.Delete(num);
                break;
            }

            case 4 :
            {
                exit(0);
                break;
            }

            default :
            {
                break;
            }
        }
     }
}

void bsystem(vector<BookItem>& booklist,vector<string>& title, vector<int>& copiesSold)
{
    string booktitle;
    int choice;

     while(true)
     {
         cout << " ================================== " <<endl;
         cout << "  Book Sales System                           " << endl;
         cout << " ================================== " << endl;
         cout << "                            (1) Book List                                " << endl;
         cout << "                            (2) Book Search                            " << endl;
         cout << "                            (3) Top 10 Best Seller                  " << endl;
         cout << "                            (4) Exit                                          " << endl << endl;
         cout << "Enter your choice :                                                    " << endl;
         cin >> choice;
          system("CLS");

         switch(choice)
        {

          case 1 :
              {

                      for(int i = 0;i < booklist.size();i++)
                      {
                          cout << booklist[i] << endl;
                      }
                   break;
              }

          case 2 :
            {
                cout << "Please enter the book title: ";
                cin >> booktitle;
                for(int i = 0;i < booklist.size();i++)
               {
                   if(booktitle == title[i]){
                    cout << booklist[i] << endl;
                    system("CLS");
                }
              else
              {
                cout << "No matches";
                system("CLS");
                 break;
               }
            }

          case 3 :
            {
               for(int i = 0;i <10 ;i++)
              {
                cout << booklist[i] << endl;
               }

                   break;
            }

          case 4:
            {
               exit(0);
               break;
            }

          default :
            {
                break;
            }
        }
     }
    }
}


int main()
{
       // You are to replace the STL vector with SortedLList that you have created
     SortedLList<BookItem>* stBooks = new SortedLList<BookItem>;
    vector<BookItem> booklist;
    vector<string> title;
    vector<int> copiesSold;
    readData("db_small.txt", stBooks,booklist,title,copiesSold);
    system("PAUSE");
    system("CLS");

    int choice;
    while(true)
    {
        cout << "======================================" << endl;
        cout << "                                       Selection                                    " << endl;
        cout << "====================================== " << endl;
        cout << "                              (1)  Sorted Link List                           " << endl;
        cout << "                              (2)  Book Sales System                      " << endl;
        cout << "                              (3)  Exit                                               " << endl << endl;
        cout << " Enter your choice :                                                          " << endl;
        cin >> choice;
        system("CLS");

        switch(choice)
        {
            case 1:
             {
                    sllist();
                    break;
             }

           case 2:
            {
                    bsystem(booklist,title,copiesSold);
                    break;
            }

           case 3 :
            {
                exit(0);
                break;
            }
           default :
            {
                break;
            }
        }
    }

   return 0;
}

#endif
