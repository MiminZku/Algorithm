#include <iostream>

using namespace std;

int n, m;
int A[1000000];
int B[1000000];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> n >> m;
    
    for(int i=0; i<n; ++i)  cin>>A[i];
    for(int i=0; i<m; ++i)  cin>>B[i];
    
    int a = 0, b = 0;
    int res[n + m];
    int i = 0;
    while(a < n && b < m)
    {
        res[i++] = A[a] < B[b] ? A[a] : B[b];
        if(A[a] < B[b]) ++a;
        else            ++b;
    }
    while(a < n)    res[i++] = A[a++];
    while(b < m)    res[i++] = B[b++];

    for(int i=0; i<n+m; ++i)
    {
        cout<<res[i]<<' ';
    }
    cout<<endl;
}