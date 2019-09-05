#include <iostream>
using namespace std;

struct Node_tree
{
    char letter;
    Node_tree **children;

    Node_tree(char letter, Node_tree *first = nullptr, Node_tree *second = nullptr, Node_tree *third = nullptr)
    {
        this->letter = letter;
        this->children = new Node_tree *[3];
        this->children[0] = first;
        this->children[1] = second;
        this->children[2] = third;
    }
};
template <typename T>
struct l_elem
{
    T *data;
    l_elem *next;

    l_elem(T *x)
    {
        this->data = x;
        this->next = nullptr;
    }
};
template <typename T>
void insert(l_elem<T> *last, T *x)
{   
    l_elem<T> *curr = last;
    while (curr->next)
    {
        curr = curr->next;
    }
    curr->next = new l_elem<T>(x);
    last = curr;
}
template <typename T>
l_elem<T> *pop(l_elem<T> *start)
{
    return start->next;
}
template <typename T>
bool isEmpty(l_elem<T> *list)
{
    if (list)
        return false;
    return true;
}

l_elem<char> *BFS(Node_tree *start)
{
    l_elem<Node_tree> *queue = new l_elem<Node_tree>(start);
    char tempLetter = ' ';
    l_elem<char> *letters = new l_elem<char>(&tempLetter);
     Node_tree tempNode = Node_tree('-1');
    l_elem<Node_tree> *qChildren = new l_elem<Node_tree>(&tempNode);

    while (!isEmpty(queue))
    {
        Node_tree *curr = queue->data;

        if (curr)
        {
            if (curr->children[0])
                insert(qChildren, curr->children[0]);
            if (curr->children[1])
                insert(qChildren, curr->children[1]);
            if (curr->children[2])
                insert(qChildren, curr->children[2]);          
            //we will insert all letters on every level
            insert(letters, &curr->letter);
        }
        queue = pop(queue);
        if (isEmpty(queue))
        {
            qChildren = pop(qChildren);
            queue = qChildren;
            qChildren  = new l_elem<Node_tree>(&tempNode);
            if(!isEmpty(queue)) 
                letters = new l_elem<char>(&tempLetter);
        }
        
    }
    letters = pop(letters);
    return letters;
}

int GetLastLevel(Node_tree *start)
{
    l_elem<Node_tree> *queue = new l_elem<Node_tree>(start);
    Node_tree temp = Node_tree('-1');
    l_elem<Node_tree> *qChildren = new l_elem<Node_tree>(&temp);
    int i = 0;
    while (!isEmpty(queue))
    {
        Node_tree *curr = queue->data;

        if (curr)
        {
            if (curr->children[0])
                insert(qChildren, curr->children[0]);
            if (curr->children[1])
                insert(qChildren, curr->children[1]);
            if (curr->children[2])
                insert(qChildren, curr->children[2]);
        }
        queue = pop(queue);
        if (isEmpty(queue))
        {
            qChildren = pop(qChildren);
            queue = qChildren;
            qChildren  = new l_elem<Node_tree>(&temp);
            i++;
        }
        
    }
    return i;
}

void printLetters(l_elem<char>* firstLetter)
{
    while (!isEmpty(firstLetter))
    {
        cout<< firstLetter->data; 
        firstLetter = pop(firstLetter);
    }
    cout <<endl;
}

int main()
{
    auto c = Node_tree('c');
    auto a = Node_tree('a');
    auto t = Node_tree('t');

    auto p = Node_tree('p');
    auto q = Node_tree('q');
    auto r = Node_tree('r', &c, &a);
    auto s = Node_tree('s', &t);

    auto x = Node_tree('x', &p, &q, &r);
    auto y = Node_tree('y', &s);

    auto b = Node_tree('b', &x, &y);

    // int level = GetLastLevel(&b);
    l_elem<char> *letters = BFS(&b);
    printLetters(letters);



    Node_tree *children[3] = {nullptr, nullptr, nullptr};
    t.children = children;
}