#include<iostream>
#include<queue>
using namespace std;

struct node {
    int data;
    node* children[20];
    int lenChildren;

    node(int value)
    {
        this->data = value;
    }
};

// Ti += max from all child 

int DFS(node start)
{
    int max = 0;
    for (int i = 0; i < start.lenChildren; i++)
    {
        int value =  DFS(*start.children[i]);
        
        if(value > max)
            max = value;     
    }

    return max + start.data;     
}

void BFS(node* start)
{
    queue<node*> q;
    if(!start)
        return;
    q.push(start);
    while (!q.empty())
    {
        node* temp = q.front();  
        q.pop();

        cout<< temp->data <<  " ";

        for (int i = 0; i < temp->lenChildren; i++)
        {
            if(temp->children[i])
                q.push(temp->children[i]);
        }
         
    }
}


int main()
{
    node root = node(15);
    node child = node(19);
    root.children[0] = &child;
    root.children[1] = new node(11);
    root.lenChildren = 2;
    root.children[1]->children[0] = new node(14);
    root.children[1]->children[1] = new node(12);
    root.children[1]->children[2] = new node(42);
    root.children[1]->lenChildren = 3;
    root.children[0]->lenChildren = 0;
    int currentMax = -1;
    int max = DFS(root);
    BFS(&root);

    return 0;
}