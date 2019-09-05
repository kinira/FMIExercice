#include <iostream>
#include <string.h>
using namespace std;

int getMax4Place(char ***forest, int rows, int cols){

    bool **visited = new bool*[rows];
    int currentMax = 0;
    int tempMax = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if(strcmp(forest[row][col], "4") == 0 && visited[row][col] != true){
                visited[row][col] = true;
                tempMax = more4s(forest, visited,row, col, rows,cols);
                if(currentMax < tempMax)
                    currentMax = tempMax;
            }
        }        
    } 
    return currentMax;   
}

int more4s(char ***forest, bool **visited, int row, int col, int rows, int cols){
    if(row + 1 < rows && cols + 1 < cols && strcmp(forest[row + 1][col + 1], "4") == 0 && visited[row + 1][col + 1] != true)
    {   
        visited[row + 1][cols + 1] = true;
        more4s(forest,visited,row+1, col+1, rows,cols) +1;
    }
    else if(row + 1 < rows && strcmp(forest[row + 1][col], "4") == 0 && visited[row + 1][col] != true)
     {   
        visited[row + 1][cols] = true;
        more4s(forest,visited,row+1, col, rows,cols) +1;
    }
     else if(row + 1 < rows && cols - 1 >= 0 && strcmp(forest[row + 1][col - 1], "4") == 0 && visited[row + 1][col - 1] != true)
     {   
        visited[row + 1][cols- 1] = true;
        more4s(forest,visited,row+1, col - 1, rows,cols) +1;
    }
     else if(cols - 1 >= 0 && strcmp(forest[row][col - 1], "4") == 0 && visited[row][col - 1] != true)
     {   
        visited[row][cols - 1] = true;
        more4s(forest,visited,row, col - 1, rows,cols) +1;
    }
     else if(row -1 >= 0 && cols - 1 >= 0 && strcmp(forest[row - 1][col- 1], "4") == 0 && visited[row -1 ][col- 1] != true)
     {   
        visited[row -1 ][cols- 1] = true;
        more4s(forest,visited,row-1, col-1, rows,cols) +1;
    }
     else if(row -1 >= 0 && strcmp(forest[row - 1][col], "4") == 0 && visited[row - 1][col] != true)
     {   
        visited[row - 1][cols] = true;
        more4s(forest,visited,row-1, col, rows,cols) +1;
    }
     else if(row -1 >= 0 && cols + 1 < cols && strcmp(forest[row - 1][col+1], "4") == 0 && visited[row - 1][col+1] != true)
     {   
        visited[row - 1][cols + 1] = true;
        more4s(forest,visited,row-1, col+1, rows,cols) +1;
    }
     else if(col + 1 < cols && strcmp(forest[row][col+1], "4") == 0 && visited[row][col+1] != true)
     {   
        visited[row][cols+ 1] = true;
        more4s(forest,visited,row, col+1, rows,cols) +1;
    }
}


bool connected(char* a1, char* a2){
    if(strcmp(a1,a2)== 0)
        return true; 
    return false;
}
int main()
{
    //demonstrate
     int rows = 4;
    int cols = 6;
    char *temp[] = {"R", "R", "1", "1","2","2",
                    "1","R","R","R","1","2",
                    "S","1","R","R","2","3",
                    "4","4","S","S","R","R",};

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
}