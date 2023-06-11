#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt=0;
    int temp = n;
    while(true){
        cnt++;
        int sum = temp/10 + temp%10;
        temp = 10*(temp%10) + sum%10;
        if(temp == n)   break;
    }
    cout<<cnt<<endl;
}