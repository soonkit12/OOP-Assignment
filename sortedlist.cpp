//retrieve,delete refer from lecture slide,tutorial
// sorted insert refer from https://www.youtube.com/watch?v=ktjKKcgdh1I

#include "sortedlist.hpp"

template <typename T>
SortedLList<T>::SortedLList()
{
    start = NULL;
}

template<typename T>
void SortedLList<T>::sortedinsert(const T& element)
{
     Node<T> * newNode = new Node<T>;
    newNode->info = element;
    if (start == NULL)
    {
        newNode->next = start;
        start = newNode;
    }
        else
        {
            current = start;
            Node<T>* End1 = NULL;
            while(current != NULL)
            {
                if(current->info > newNode->info)
                {
                    break;
                }
                    else
                    {
                        End1 = current;
                        current = current->next;
                    }
            }

            if(current == start)
            {
                newNode->next = start;
                start = newNode;
            }
                else
                {
                    newNode->next = current;
                    End1->next = newNode;

                }
        }
}

//template<typename T>
//bool SortedLList<T>::retrieve(int& element)
//{
 // bool found = false;
//	Node<T>* ptr = start;
//	while (ptr != NULL && !found) {
//		if (ptr->info == target) {
//			found = true;
//			element = ptr->info;
//		}
//		if (!found)
//			ptr = ptr->next;
//	}
//	return found;

//}


template<typename T>
bool SortedLList<T>::Delete(int& element)
{
     if ( start == NULL )
     {
        return false;
      }

    else
    {
	   Node<T> *ptr = start;
	   int i = 2;
	   if ( 1 == element ) {
		start = start->next;
		  delete ptr;
		  return true;
		}

    while ( ptr->next != NULL && i != element) {
		ptr = ptr->next;
		i++;
    }

    if(ptr->next == NULL){
        cout << "item not exist" << endl;
        system("CLS");
    }
    else{
        Node<T> *tempPtr = ptr->next;
        ptr->next = tempPtr->next;
        delete tempPtr;
    }
}

  }

template class SortedLList<int>;
template class SortedLList<BookItem>;
