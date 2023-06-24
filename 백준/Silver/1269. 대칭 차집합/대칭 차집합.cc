#include <iostream>

using namespace std;

bool A[100000001];
bool B[100000001];

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    
    int n, max = 0;
    for(int i=0; i<a; i++){
        cin>>n;
        A[n] = true;
        if(max<n)   max = n;
    }
    for(int i=0; i<b; i++){
        cin>>n;
        B[n] = true;
        if(max<n)   max = n;
    }
    int cnt = 0;    
    for(int i=1; i<=max; i++){
        if(A[i] && B[i])    continue;
        if(!A[i] && !B[i])  continue;
        cnt++;
    }
    cout<<cnt<<endl;
}