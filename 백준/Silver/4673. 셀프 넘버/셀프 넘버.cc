#include <iostream>

using namespace std;

bool created[100001];

int d(int n){
    int sum=n;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);

    for(int i=0; i<=10000; i++){
        int n = d(i);
        if(n>10000) continue;;
        created[n] = true;
    }
    for(int i=1; i<=10000; i++){
        if(created[i])  continue;
        cout<<i<<'\n';
    }
}