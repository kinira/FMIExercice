#include <iostream>
using namespace std;

template <typename T>
struct l_elem{
    T data;
    l_elem<T>* next;
};

template <typename T>
class List{
    public: 
        List();
        ~List();
        List(const List&);
        List& operator=(const List&);
        //main functions
        bool empty() const;
        void iterStart(l_elem<T>* = nullptr);
        l_elem<T>* iter();
        void toEnd(const T&);
        void insertAfter(l_elem<T>*, const T&);
        void insertBefore(l_elem<T>*, const T&);
        void deleteAfter(l_elem<T>*, const T&);
        void deleteBefore(l_elem<T>*, const T&);
        void deleteElem(l_elem<T>*, const T&);
        void print() const;
        int length() const;
    private: 
        l_elem<T> *start, *end, *current;
        void copyList(const List&);
        void deleteList();
};
template <typename T>
List<T>::List(){
    start = end = nullptr;
}
template <typename T>
List<T>::~List()
{
    deleteList();
}
template <typename T>
List<T>::List(const List& other)
{
    copyList(other);
}
template <typename T>
List<T>& List<T>::operator=(const List& other){
    if(this != &other)
    {
        deleteList();
        copyList(other);
    }
    return *this;
}
template <typename T>
void List<T>::copyList(const List& other)
{
    start = end = current = nullptr;
    l_elem<T>* p = other.start;
    while (p)
    {
        toEnd(p->data);
        p = p->next;
    }
}
template <typename T>
void List<T>::deleteList()
{
    l_elem<T> * p;
    while (start)
    {
        p = start; 
        start = start->next;
        delete p;
    }
    end = nullptr;
}
template <typename T>
void List<T>::iterStart(l_elem<T> *toStart){
    if(toStart) current = toStart;
    else current = start;
}
template <typename T>
l_elem<T>* List<T>::iter()
{
    l_elem<T> *temp = current; 
    if(current) current = current->next;
    return temp;
}
template <typename T>
void List<T>::toEnd(const T& x){
    l_elem<T>* tempEnd = end;
    end = new l_elem<T>;
    end->data = x;
    end->next = nullptr;
    if(tempEnd)
        tempEnd->next = end;
    else start = end;
}

template <typename T>
void List<T>::insertBefore(l_elem<T>* after, const T& x)
{
    l_elem<T>* temp = new l_elem;
    *temp = *after;
    if(after == end) end = temp;
    after->data = x;
    after->next = temp;
}
template <typename T>
void List<T>::insertAfter(l_elem<T>* before, const T& x)
{
    l_elem<T>* temp = new l_elem;
    temp->data = x;
    temp->next = before->next;
    before->link = temp;
}
template <typename T>
void List<T>::deleteAfter(l_elem<T>* after, const T& x)
{
    if(after->next != nullptr)
    {
        l_elem<T> *temp = after->next;
        x = temp->next;
        temp->next = after->next;
        if (temp == end) 
            end = after;
        delete temp;        
    }
    else
    {
        exit(1);
    }    
}
template <typename T>
void List<T>::deleteBefore(l_elem<T>* before, const T& x)
{
    if(before != start)
    {
        l_elem<T>* temp = start;
        while (temp->next != before) 
        {
            temp = temp->next;
        }
        deleteElem(temp, x);
    }
    else
    {
        exit(1);
    }    
}
template <typename T>
void List<T>::deleteElem(l_elem<T>* el, const T& x)
{
    if (el == start)
    {
        x = el->data;
        if (start == end)
        {
            start = end = nullptr;
        }
        else 
            start = start->next;
        delete el;
    }
    else
    {
        l_elem<T>* temp = start; 
        while (temp->next != el)
        {
            temp = temp->next;
        }
        deleteAfter(temp,x);
    } 
}
template <typename T>
void List<T>::print() const
{
    l_elem<T>* temp = start; 
    while (temp)
    {
        cout << temp->data << ' ';
    }
    
}
template <typename T>
int List<T>::length() const
{
    int i = 0;
    while (start != end)
    {
        i++;
        start = start->next;
    }
    return i;    
}