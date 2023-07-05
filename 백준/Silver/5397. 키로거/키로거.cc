#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Sol(const string& input){
    vector<char> prev, next;
    for(const char& ch : input){
        if(ch == '-'){
            if(prev.size()) prev.pop_back();
        }
        else if(ch == '<'){
            if(prev.size()){
                char top = *(prev.end()-1);
                prev.pop_back();
                next.push_back(top);
            }
        }
        else if(ch == '>'){
            if(next.size()){
                char top = *(next.end()-1);
                next.pop_back();
                prev.push_back(top);
            }
        }
        else{   // 알파벳일 때
            prev.push_back(ch);
        }
    }
    for(char ch : prev) cout<<ch;
    for(int i=next.size()-1; i>=0; i--){
        cout<<next[i];
    }cout<<'\n';
}

int main(){
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        string input;
        cin>>input;
        
        Sol(input);
    }
}