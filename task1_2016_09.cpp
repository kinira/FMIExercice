#include <iostream>
#include <string.h>
#include <map>
using namespace std;

struct index
{
    int left;
    int right;
};

struct elem
{
    char key;
    int positions;
    elem *next;
};

class List
{
private:
    elem *start;
    elem *end;
    void deleteList()
    {
        delete start;
        delete end;
    }

public:
    List();
    ~List();
    void addElem(const char &key, const int position);
    void removeElemFirstOcc(const char &key);
    void removeElem(elem &el);
    elem *dequeque();
    elem *exists(const char &key);
    elem *pop();
    bool isEmpty();
    int length();
};

List::~List()
{
    deleteList();
}

List::List()
{
    this->end = nullptr;
    this->start = nullptr;
}

void List::addElem(const char &key, const int position)
{
    elem *p = new elem();
    p->key = key;
    p->positions = position;
    p->next = nullptr;

    if (this->start)
        this->end->next = p;
    else
        this->start = p;

    this->end = p;
}

void List::removeElemFirstOcc(const char &key)
{
    if (this->start->key == key)
    {
        this->start = this->start->next;
        return;
    }
    elem *prev = this->start;
    while (prev->next)
    {
        elem *current = prev->next;
        if (current->key == key)
        {
            prev->next = current->next;
            return;
        }
        prev = prev->next;
    }
}

elem *List::exists(const char &key)
{
    elem *curr = this->start;
    while (curr)
    {
        if (curr->key == key)
        {
            return curr;
        }
        curr = curr->next;
    }

    return nullptr;
}

int List::length()
{
    int counter = 0;
    elem *curr = this->start;
    while (curr)
    {
        counter++;
        curr = curr->next;
    }

    return counter;
}

elem *List::pop()
{
    elem *p = this->start;
    if (this->start->next)
    {
        this->start = this->start->next;
    }
    else
    {
        this->start = nullptr;
        this->end = nullptr;
    }
    return p;
}

bool List::isEmpty()
{
    if (!this->start && !this->end)
        return true;

    return false;
}

elem *List::dequeque()
{
    if (this->end)
    {
        elem *p = this->end;
        this->removeElem(*p);
        return p;
    }
    return nullptr;
}

void List::removeElem(elem &el)
{
    elem *curr = this->start;
    elem *prev = nullptr;
    while (curr)
    {
        if (curr == &el)
        {
            if (prev)
            {
                prev->next = curr->next;
                return;
            }
            else if (this->end)
            {
                this->start = this->end;
                return;
            }
            else
            {
                this->start = nullptr;
                this->end = nullptr;
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return;
}

int findMaxDistance(char *sentance)
{
    int length = strlen(sentance);
    List dict;
    int maxDistance = -1;
    for (int i = 0; i < length; i++)
    {
        elem *hasItem = dict.exists(sentance[i]);
        if (hasItem)
        {
            int currDistance = i - hasItem->positions;
            if (currDistance > maxDistance)
            {
                maxDistance = currDistance;
            }
        }
        else
        {
            dict.addElem(sentance[i], i);
        }
    }
    return maxDistance;
}

int main()
{
    char *temp = "this is just an example";
    // int  t = findMaxDistance(temp);
    elem p0;
    p0.key = 'c';
    p0.positions = 12;
    List l;
    l.addElem('c', 12);
    l.addElem('d', 23);
    l.addElem('e', 1);
    l.addElem('f', 15);
    l.addElem('g', 12);
    l.addElem('h', 23);
    l.addElem('l', 1);
    l.addElem('m', 15);
    l.addElem('k', 12);
    l.addElem('q', 23);
    l.addElem('i', 1);
    l.addElem('p', 15);

    int n = l.length();
    elem *first = l.pop();
    int n1 = l.length();
    elem *last = l.dequeque();
    elem *toberemoved = l.exists('i');
    l.removeElem(*toberemoved);

    return 1;
}