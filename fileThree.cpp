#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

struct Node_tree
{
    int letter;
    Node_tree *children;

    Node_tree(int letter, int n, Node_tree *children)
    {
        this->letter = letter;
        this->children = new Node_tree[n];
        for (int i = 0; i < n; i++)
        {
            this->children[i] = children[i];
        }
    }
    Node_tree()
    {
        this->letter = -1;
        this->children = nullptr;
    }
};

struct NumLength
{
    char *numbers;
    int length;
};

char *readTree(char *path)
{
    ifstream threeFile;
    threeFile.open(path);
    char *arr = new char[100];
    char x;
    int i = 0;
    while (threeFile >> x)
    {
        arr[i] = x;
        i++;
    }
    return arr;
}
int getNumber(char numbers[100], int length)
{
    int number = 0;

    for (int i = length - 1; i >= 0; i--)
    {
        number += ((int)numbers[i] - 48) * pow(10, (length - 1 - i));
    }
    return number;
}
int readNumber(char *arrTree, int &i)
{
    NumLength nl;
    nl.numbers = new char[100];
    nl.length = 0;
    while (arrTree[i] != '(')
    {
        nl.numbers[nl.length] = arrTree[i];
        nl.length++;
        i++;
    }
   return getNumber(nl.numbers, nl.length);
}



Node_tree *buildThree(char *arrTree, int &i)
{
    Node_tree trees[100];
    int treeCount = 0;

    if (arrTree[i] != '(')
    {
       return trees;
    }
    i++;
    while (arrTree[i] != ')')
    {        
        Node_tree t;
        t.letter = readNumber(arrTree, i);
        trees[treeCount] = t;
        treeCount++;

        if(arrTree[i++] != '(') throw "Expected ( for starting the children of " + t.letter;
        Node_tree *children = buildThree(arrTree, i);
        if(arrTree[i] != ')') throw "Expected ) for closing the children of " + t.letter;

        t.children = children;
        i++;
        if(arrTree[i] == ',') {
            i++;   
            if(arrTree[i] == '(')
            i++;
            else 
                "Expected ( for continue the children of " + t.letter;
        }
           

        // ) or ,
    }
    return trees;
}

int main()
{
    char *arrThree = readTree("three.txt");
    int i = 0;
    auto tree = buildThree(arrThree, i);
    return 1;
}