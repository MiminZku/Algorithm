#include <iostream>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL);
    cin>>n;
    if(n==1)    return 0;
    int primeNum = 2;
    while(n!=1){
        if(n%primeNum)  primeNum++;
        else{
            cout<<primeNum<<endl;
            n /= primeNum;
        }
    }
}