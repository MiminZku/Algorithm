#include <iostream>

using namespace std;

int mat[64][64];
int n;

int WhatColor(int rStart, int rEnd, int cStart, int cEnd){
    int first = mat[rStart][cStart];
    for(int i=rStart; i<=rEnd; i++){
        for(int j=cStart; j<=cEnd; j++){
            if(mat[i][j]!=first)    return -1;
        }
    }
    return first;
}

void Recursive(int rStart, int rEnd, int cStart, int cEnd){
    int color = WhatColor(rStart,rEnd,cStart,cEnd);
    if(color==0)        cout<<0;
    else if(color==1)   cout<<1;
    else{
        cout<<"(";
        int rMid = (rStart+rEnd)/2;
        int cMid = (cStart+cEnd)/2;
        Recursive(rStart, rMid, cStart, cMid);
        Recursive(rStart, rMid, cMid+1, cEnd);
        Recursive(rMid+1, rEnd, cStart, cMid);
        Recursive(rMid+1, rEnd, cMid+1, cEnd);
        cout<<")";
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        char str[65] = {};
        cin>>str;
        for(int j=0; j<n; j++){
            mat[i][j] = str[j]-'0';
        }        
    }
    Recursive(0, n-1, 0, n-1);
    cout<<endl;
}