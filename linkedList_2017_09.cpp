#include<iostream>
using namespace std; 

struct ll_elem{
    int value;
    ll_elem* next;
};

class List{
    private: 
    ll_elem *start;
    ll_elem *end;
    ll_elem *current;
    void copyList(const List&);
    void deleteList();
    public:
    //cononic 4
    List();
    ~List();
    List(const List&);
    List operator=(const List&);
    //additional
    int length() const;
    void removeElem(const ll_elem&);
    void addElemAfter(ll_elem&, int&);
    void addElemToEnd(int&);
    bool empty() const;
    void iterStart(ll_elem* = nullptr);
    ll_elem* iter();
};

int List::length() const
{
    int i = 0;
    while (start != end)
    {
        i++;
        start = start->next;
    }
    return i;
}
bool List::empty() const
{
    if(start == nullptr)
        return true;
    return false;
}
void List::addElemToEnd(int &x)
{
    ll_elem *p;
    p->value = x;
    p->next = nullptr;
    end->next = p;
    end = p;
}

void List::addElemAfter(ll_elem &el, int &x)
{
    ll_elem *p;
    p->value = x;
    p->next = el.next;
    el.next = p;
}
void List::removeElem(ll_elem &el)
{
    if (&el == end)
    
    
}