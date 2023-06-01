#include <iostream>

using namespace std;

int n,m;
char str[1000001];
int pLen;

bool Check(int idx){
    char ch = 'I';
    for(int i=0; i<pLen; i++){
        if(str[idx+i] == ch){
            if(ch=='I') ch = 'O';
            else        ch = 'I';
        }
        else    return false;
    }
    return true;
}

int main(){
    cin>>n>>m>>str;
    pLen = 1+2*n;
    int cnt = 0;
    for(int i=0; i<=m-pLen; i++){
        if(str[i]=='O') continue;
        if(Check(i)){
            cnt++;
            // i += pLen-4;
        }
    }
    cout<<cnt<<endl;
}