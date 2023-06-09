#include <iostream>

using namespace std;

int n;
int m;
bool isBroken[10];
int cur = 100;

int LenOfNum(int n){
    if(n==0)    return 1;
    int cnt=0;
    while(n>0){
        n/=10;
        cnt++;
    }
    return cnt;
}

bool Possible(int n){
    if(n==0){
        if(isBroken[0]) return false;
        else            return true;
    }
    while(n>0){
        if(isBroken[n%10])  return false;
        n/=10;
    }
    return true;
}

int main(){
    cin>>n>>m;
    while(m--){
        int k;
        cin>>k;
        isBroken[k] = true;
    }

    // 무지성 + or - 연타
    int minimum = n>cur ? n-cur : cur - n;
    // cout<<"minimum : "<<minimum<<endl;    

    // 숫자 버튼으로 목표보다 큰 수 중 가장 낮은 수 맞추고 -
    int cnt;
    int temp = n;
    while(true){
        if(Possible(temp))  break;
        temp++;
        if(temp-n > minimum)    break;
    }
    cnt = LenOfNum(temp) + (temp - n);
    if(cnt < minimum)   minimum = cnt;
    // cout<<"minimum : "<<minimum<<endl;

    // 숫자 버튼으로 목표보다 낮은 수 중 가장 큰 수 맞추고 +
    temp = n;
    while(true){
        if(Possible(temp))  break;
        temp--;
        if(temp<0)  break;
    }
    if(temp>=0) cnt = LenOfNum(temp) + (n - temp);
    else        cnt = 2147483647;
    if(cnt < minimum)    minimum = cnt;
    // cout<<"minimum : "<<minimum<<endl;

    cout<<minimum<<endl;
}