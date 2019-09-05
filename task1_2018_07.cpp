#include<iostream>
#include<string.h>
using namespace std; 

char** sortLex(char** arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (strcmp(arr[i-1], arr[i])>0)
        {
            swap(arr[i-1],arr[i]);
        }        
    }   
    return arr; 
}

void print(char** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int n = 7;
    char* temp[] = {"1","54","123","27","2", "43","32"};
    char** sorted =  sortLex(temp,5);
    print(sorted,n);
    return 1;
}