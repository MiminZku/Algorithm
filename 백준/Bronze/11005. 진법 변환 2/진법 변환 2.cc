#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    int b;
    cin>>n>>b;
    vector<char> str;
    int d,m;
    while(true){
        d = n/b;
        m = n%b;
        if(m<10)    str.push_back('0'+m);
        else        str.push_back('A'+m-10);
        if(d<b){
            if(d<10)    str.push_back('0'+d);
            else        str.push_back('A'+d-10);
            break;    
        }
        n = d;
    }
    reverse(str.begin(),str.end());
    bool passZero = false;
    for(char c : str){
        if(passZero)    cout<<c;
        else if(c=='0')   continue;
        else{
            cout<<c;
            passZero = true;
        }
    }cout<<endl;
}