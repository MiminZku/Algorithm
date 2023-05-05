#include <iostream>
#include <string>
#include <set>

#define fastio cin.tie(nullptr), ios::sync_with_stdio(false);

using namespace std;

int main(){
    fastio;
    int n;
    cin>>n;
    cin.ignore();
    set<string, greater<string>> treeSet;
    for(int i=0; i<n; i++){
        string name, log;
        cin>>name>>log;
        if(log == "enter"){
            treeSet.insert(name);
        }
        else{
            treeSet.erase(name);
        }
    }
    for(string str: treeSet){
        cout<<str<<'\n';
    }
}