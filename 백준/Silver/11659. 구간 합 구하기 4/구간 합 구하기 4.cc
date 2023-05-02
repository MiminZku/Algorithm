#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int arr[n+1] ={0};
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        arr[i] = arr[i-1]+k;
    }              
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<'\n';
    }
}