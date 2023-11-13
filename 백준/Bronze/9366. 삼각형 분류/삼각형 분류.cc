#include <iostream>

using namespace std;

int WhatTriangle(int edges[3]){
    int sum=0, longest = edges[0];
    for(int i=0; i<3; i++){
        sum+=edges[i];
        if(edges[i] > longest)  longest = edges[i];
    }
    if(sum-longest <= longest)    return 0;
    if(edges[0] == edges[1] && edges[1] == edges[2])    return 3;
    else if(edges[0] == edges[1] || edges[1] == edges[2] || edges[0] == edges[2])
        return 2;
    else return 1;
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cout<<"Case #"<<i<<": ";
        int edges[3];
        for(int i=0; i<3; i++)  cin>>edges[i];
        if(!edges[0])   break;
        int res = WhatTriangle(edges);
        if(!res)    cout<<"invalid!\n";
        else if(res == 1){
            cout<<"scalene\n";   
        }
        else if(res == 2){
            cout<<"isosceles\n";   
        }
        else if(res == 3){
            cout<<"equilateral\n";   
        }
    }
}