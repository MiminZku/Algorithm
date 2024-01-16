#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> strArr;
string res;

int GetDistance(string& A, string& B)
{
    int res = 0;
    for(int i=0; i<m; i++)
    {
        if(A[i] != B[i])    res++;
    }
    return res;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n>>m;
    cin.ignore();

    strArr.resize(n);
    res.resize(m);

    for(int i=0; i<n; i++)
    {
        cin>>strArr[i];
    }

    for(int j=0; j<m; j++)
    {
        int typeCnt[4] = {0,0,0,0}; // A, C, G, T

        for(int i=0; i<n; i++)
        {
            if(strArr[i][j] == 'A')         typeCnt[0]++;
            else if(strArr[i][j] == 'C')    typeCnt[1]++;
            else if(strArr[i][j] == 'G')    typeCnt[2]++;
            else if(strArr[i][j] == 'T')    typeCnt[3]++;
        }

        int maxNum = 0;
        int maxType;
        for(int i=0; i<4; i++)
        {
            if(maxNum < typeCnt[i])
            {
                maxNum = typeCnt[i];
                maxType = i;
            }
        }

        if(maxType == 0)        res[j] = 'A';
        else if(maxType == 1)   res[j] = 'C';
        else if(maxType == 2)   res[j] = 'G';
        else if(maxType == 3)   res[j] = 'T';
    }

    int hd = 0;
    for(int i=0; i<n; i++)
    {
        hd += GetDistance(res, strArr[i]);
    }

    cout<<res<<endl;
    cout<<hd<<endl;
}