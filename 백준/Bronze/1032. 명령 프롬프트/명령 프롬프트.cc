#include <iostream>
#include <vector>

using namespace std;

vector<string> strArr;
int strLen;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    int n;
    cin>>n;
    strArr.resize(n);
    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        strArr[i] = str;    
    }
    strLen = strArr[0].size();
    bool isAllSame[strLen];

    for(int i=0; i<strLen; i++)
    {
        isAllSame[i] = true;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<strLen; j++)
        {
            
            if(strArr[i][j] != strArr[0][j])
            {
                isAllSame[j] = false;
            }
        }
    }

    for(int i=0; i<strLen; i++)
    {
        if(isAllSame[i])
        {
            cout<<strArr[0][i];
        }
        else
        {
            cout<<"?";
        }
    }
    cout<<endl;
}