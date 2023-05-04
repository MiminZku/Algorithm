#include <iostream>
#include <string>
#include <unordered_set>

#define fastio cin.tie(nullptr); ios::sync_with_stdio(false);

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    cin.ignore();
    unordered_set<string> s;
    for(int i=0; i<n; i++){
        string str;
        getline(cin,str);
        s.insert(str);
    }
    int count = 0;
    for(int i=0; i<m; i++){
        string str;
        getline(cin, str);
        if(s.find(str)!=s.end()){
            count++;
        }
    }
    cout<<count;
}