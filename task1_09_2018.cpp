#include<iostream>
#include<string.h>
using namespace std;


int indexOfSpace(char* word, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (word[i] == ' ')
        {
            return i;
        }
        
    }
    return -1;
}

void printLettersCount(char* word)
{
    int length = strlen(word);
    int counter = 0;
    int spaceIndex = indexOfSpace(word,length);
    if (spaceIndex == -1)
    {
        cout<< length << " ";
    }
    else
    {
        cout << spaceIndex << ' ' << length - spaceIndex - 1 << ' ';
    } 
}

bool isSorted(char* oneRow[30], int rows)
{
    for (int i = 1; i < rows; i++)
    {
        if (strcmp(oneRow[i-1], oneRow[i]) > 0)
        {
            return false;
        }        
    }
    return true;    
}
void revealPassword(char*** bib, int rows, int cols){

    int middle = cols/2;

     for (int i = 0; i < rows; i++)
     {
         if (isSorted(bib[i], rows))
         {
              printLettersCount(bib[i][middle]);
         }         
     }
}

int main()
{
    int rows = 3;
    int cols = 3;
    char* temp[] = {"Algebra", "Analitichna geometria", "matematicheski analiz", "uvod v programiraneto",
                    "obektno-orientirano programirane", "structuri ot danni i programirane", "bazi ot danni",
                    "funktionalno programirane", "izkustven intelekt"};

    char*** arr = new char**[rows];
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

    revealPassword(arr,rows,cols);
}