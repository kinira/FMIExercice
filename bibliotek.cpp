#include <iostream>
#include <string.h>
using namespace std;

const int n = 30;

const bool isSorted(int n, char *a[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                return false;
            }
        }
    }

    return true;
}

bool isEven(int n)
{
    return n % 2 == 0;
}

void revalPassword(char ***arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        if (isSorted(cols, arr[i]))
        {
            int index = isEven(cols / 2) ? (cols / 2) - 1 : cols / 2;
            auto word = arr[i][index];
            int len = strlen(word);
            int g = 0;
            for (int i = 0; i <= len; i++)
            {
                if (word[i] == ' ' || word[i] == '\0')
                {        
                    cout << i -g << ' ';
                    g = i;
                }
            }
            
        }
    }
}

int main()
{
    auto n = 3;
    int rows = 3;
    int cols = 3;
    char *temp[] = {"Algebra", "Analitichna geometria", "matematicheski analiz", "uvod v programiraneto",
                    "obektno-orientirano programirane", "structuri ot danni i programirane", "bazi ot danni",
                    "funktionalno programirane", "izkustven intelekt"};

    char *** arr = new char**[rows];
    int c = 0;

    for (int row = 0; row < rows; row++)
    {   
        arr[row] = new char*[cols];

        for (int col = 0; col < cols; col++)
        {
           arr[row][col] = temp[c]; 
            c++;
        }
    }
   revalPassword (arr,rows,cols);
    //delete new
   for (int row = 0; row < rows; row++)
    {   
       delete[] arr[row];        
    }
    delete[] arr;
    cout << endl;
}