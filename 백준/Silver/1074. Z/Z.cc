#include <iostream>

using namespace std;

int n,r,c;

int Row(int row)
{
    if(row == 0)    return 0;
    if(row == 1)    return 2;
    int e = 0;
    while(row >= 1<<e)
    {
        e++;
    }
    e--;
    return (1<<(e*2+1)) + Row(row - (1<<e));    
}

int Col(int col)
{
    if(col == 0)    return 0;
    if(col == 1)    return 1;
    int e = 0;
    while(col >= 1<<e)
    {
        e++;
    }
    e--;
    return (1<<(e*2)) + Col(col - (1<<e));
}

int main()
{
    cin>>n>>r>>c;
    cout<<Row(r)+Col(c)<<endl;
}