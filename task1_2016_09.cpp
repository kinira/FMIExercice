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
    elem *current;
    elem *start;
    elem *end;
    void deleteList()
    {
        delete current;
        delete start;
        delete end;
    }

public:
    List();
    ~List();
    List(List &);
    void addElem(const char &key,const int position);
    void removeElem( const char &key);
    elem *exists(const char &key);
};

List::~List()
{
    deleteList();
}

List::List()
{
    this->current = nullptr;
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

void List::removeElem(const char &key)
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
    elem a;
    a.key = 's';

    elem* b = &a;

    char *temp = "this is just an example";
    int  t = findMaxDistance(temp);
    return 1;
}