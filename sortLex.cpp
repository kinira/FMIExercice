#include <iostream>
#include <string.h>
using namespace std;

const char **sortLex(int n, const char *a[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                swap(a[i], a[j]);
            }
        }
    }

    return a;
}
int main()
{
    auto n = 3;
    const char *strarray[] = {"hey", "sup", "dogg"};

    // char** b = new char*[5];
    // b[0] = "asdasd";
    // b[1]  = "asdasd";

    auto sorted = sortLex(n, strarray);
    for (int i = 0; i < n; i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;
}