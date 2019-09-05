#include <iostream>
#include <iterator> 
#include <map> 
using namespace std; 

struct positions{
    int start;
    int end;
    int maxDisance;
};

struct elem{
    char value; 
    int pos; 
    elem* next;
};

elem* findElem (elem* curr, char x)
{
    elem* iter = curr;
    while (iter->next)
    {
        if (iter->value == x)
            return iter;
        iter = iter->next;
    }
    return nullptr;
}

elem* insert(elem* curr, char x, int pos)
{
    elem* iter = curr;
    while (iter->next)
    {
        iter = iter->next;
    }
    iter->next = new elem();
    iter->next->pos = pos;
    iter->next->value = x;
    return curr;    
}

positions findMaxDisatance(char* sentance)
{
    map<char,int> charPositions;
    map<char,int>::iterator itEnd = charPositions.end();
    int i = 0;   
    positions bestPos = positions();
    bestPos.maxDisance = -1;
    while (sentance[i] != '\0')
    {   
        map<char,int>::iterator existis = charPositions.find(sentance[i]);
        if (existis == itEnd)
            charPositions.insert(pair<char,int>(sentance[i],i));
        else 
        {
            int currDistance = i- existis->second;
            if(currDistance > bestPos.maxDisance)
            {
                bestPos.maxDisance = currDistance; 
                bestPos.start = existis->second;
                bestPos.end = i;
            }           
        } 
        i++;
    }    

    return bestPos;
}



positions findMaxDisatanceWOMap(char* sentance)
{
    elem* charPositions = new elem();

    int i = 0;   
    positions bestPos = positions();
    bestPos.maxDisance = -1;
    while (sentance[i] != '\0')
    {   
        elem* exists  = findElem(charPositions, sentance[i]);
        if (exists)
        {
            int currDistance = i- exists->pos;
            if(currDistance > bestPos.maxDisance)
            {
                bestPos.maxDisance = currDistance; 
                bestPos.start = exists->pos;
                bestPos.end = i;
            }           
        }
        else 
           charPositions = insert(charPositions, sentance[i], i);
     
        i++;
    }    

    return bestPos;
}


int main ()
{
    char *sentance = "this is just a simple example";
    positions res = findMaxDisatanceWOMap(sentance);
    cout << res.start << ' ' <<res.end << ' max distance' << res.maxDisance;
    cout<<endl;
    return 0;
}