#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int next = 0;
    int result = 0;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        if(k == next)
        {
            result++;
            next = (next+1)%3;
        }
    }
    cout<<result<<endl;
}