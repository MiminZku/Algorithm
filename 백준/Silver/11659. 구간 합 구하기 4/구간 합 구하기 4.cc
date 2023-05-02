#include <cstdio>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n+1] ={0};
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d",&k);
        arr[i] = arr[i-1]+k;
    }              
    for(int i=0; i<m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",arr[b]-arr[a-1]);
    }
}