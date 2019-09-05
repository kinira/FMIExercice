#include <iostream>
using namespace std;

struct Node_tree
{
    int number;
    Node_tree **children;

    Node_tree(int number, int n)
    {
        this->number = number;
        this->children = new Node_tree *[n];
        for (int i = 0; i < n; i++)
        {
            this->children[i] = nullptr;
        }
    }
};


Node_tree **fillVertexes(Node_tree **vert, int nodeLen, int *elems, int k, int i)
{
    Node_tree **children = new Node_tree*[nodeLen*k];
    int childCounter = 0;
    for (int node = 0; node < nodeLen; node++)
    {
        for (int j = 0; j < k; j++)
        {
            vert[node]->children[j] = new Node_tree(elems[i + j], k);

            children[childCounter] = vert[node]->children[j];
            
            childCounter++;
        }
    }

    return children;
}

Node_tree *BuildTree(int *elements, int k, int n)
{
    Node_tree *tree = new Node_tree(elements[0], k);
    Node_tree **vertexes = new Node_tree*[k];
    vertexes[0] = tree;
    int numV = 1;
    int leftNumbers = n - 1;
    int i = 1;

    int levels = leftNumbers / k;
    for (int level = 0; level < levels; level++)
    {
        Node_tree** children = fillVertexes(vertexes,numV,elements,k,i);
        vertexes = children;
        numV = numV * k;
        i += numV;
    }
    cout<< levels;
    return tree;
}

int main()
{
    int elements[] = {1,2,3,4,5,6,7,8,9,10};
    Node_tree *tree = BuildTree(elements, 3, 10);
    return 0;
}