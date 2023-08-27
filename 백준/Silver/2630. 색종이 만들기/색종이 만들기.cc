#include <iostream>

using namespace std;

int n;
int mat[128][128];
int white, blue;

int GetColor(int rStart, int rEnd, int cStart, int cEnd)
{
    int first = mat[rStart][cStart];
    for(int i=rStart; i<=rEnd; i++)
    {
        for(int j=cStart; j<=cEnd; j++)
        {
            if(mat[i][j]!=first)    return -1;
        }
    }
    return first;
}

void Recur(int rStart, int rEnd, int cStart, int cEnd)
{
    int color = GetColor(rStart, rEnd, cStart, cEnd);
    if(color == 0)        white++;
    else if(color == 1)   blue++;
    else
    {
        int rMid = (rStart+rEnd)/2;
        int cMid = (cStart+cEnd)/2;
        Recur(rStart, rMid, cStart, cMid);
        Recur(rStart, rMid, cMid+1, cEnd);
        Recur(rMid+1, rEnd, cStart, cMid);
        Recur(rMid+1, rEnd, cMid+1, cEnd);
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }
    Recur(0, n-1, 0, n-1);
    cout<<white<<'\n'<<blue<<'\n';
}