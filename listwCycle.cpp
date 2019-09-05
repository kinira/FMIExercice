#include <iostream>
using namespace std;

template <typename T>
struct elem_cycle
{
    T data;
    elem_cycle<T> *next;
};

template <typename T>
bool hasKnot(const elem_cycle<T> *start, int n)
{
    elem_cycle<T> *iter = start;

    while (iter != nullptr)
    {
        elem_cycle<T> *curr = iter->next;
        while (curr != nullptr)
        {
            if (curr == iter)
            {
                return true;
            }
            curr = curr->next;
        }
        iter = iter->next;
    }

    return false;
}
elem_cycle<int> *readList()
{
    int a[] = {5, 2, 3, 4, 2};
    int n = 5;

    elem_cycle<int> *start = new elem_cycle<int>;

    elem_cycle<int> *curr = start;
    for (int i = 0; i < n; i++)
    {
        curr->data = a[i];

        curr->next = i < n - 1 ? new elem_cycle<int> : nullptr;
        curr = curr->next;
    }

    return start;
}

int main()
{
    auto elems = readList();
    bool isAknow = hasKnot(elems);
    return 0;
}
