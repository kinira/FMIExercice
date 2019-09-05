#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
using namespace std;

template <typename T>
struct elem
{
    T value;
    elem *next;
    elem *nextKti;
};

elem<int> *readList(char *path)
{
    ifstream numbersFile;
    numbersFile.open(path);
    int numbers[100];
    int x;
    int n = 0;

    while (numbersFile >> x)
    {
        numbers[n] = x;
        n++;
    }
    numbersFile.close();

    elem<int> *head = new elem<int>;
    elem<int> *temp = new elem<int>;
    elem<int> *curr = new elem<int>;
    elem<int> *kti = new elem<int>;
    curr->value = numbers[0];
    temp = curr;
    head = curr;
    kti = curr;
    int k = ceil(sqrt(n));
    int tillk = 1;
    for (int i = 1; i < n; i++)
    {
        curr = new elem<int>;
        curr->value = numbers[i];
        temp->next = curr;
        temp = curr;
        if (tillk == k)
        {
            kti->nextKti = curr;
            kti = curr;
            tillk = 0;
        }
        tillk++;
    }
    curr->next = nullptr;

    cout << endl;

    return head;
}

bool walk(const elem<int>& start, int x)
{
    elem<int> *curr = start.next;

    while (curr != nullptr && curr != start.nextKti)
    {
        if (curr->value == x)
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool walkSkip(const elem<int> &curr, const elem<int> *prev, int x)
{
    if (curr.value == x)
        return true;

    if (x < curr.value && prev != nullptr && prev->value < x)
        return walk(*prev, x);

    if (x > curr.value)
    {
        if (curr.nextKti != nullptr)
            return walkSkip(*curr.nextKti, &curr, x);
        else
            return walk(curr, x);
    }
}



bool member(const elem<int>& start, int x)
{
    return walkSkip(start, nullptr, x);
}


int main()
{
    char *path = "numbers.txt";
    elem<int> *head = readList(path);
    cout << member(*head, 150);
    return 1;
}