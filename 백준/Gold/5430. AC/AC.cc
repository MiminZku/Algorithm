#include <iostream>
#include <deque>

using namespace std;

int t;

void Print(deque<int>& arr, int dir){
    int len = arr.size();
    cout<<'[';
    if(dir==1){
        for(int i=0; i<len; i++){
            cout<<arr[i];
            if(i<len-1) cout<<',';
        }
    }
    else{
        for(int i=len-1; i>=0; i--){
            cout<<arr[i];
            if(i>0) cout<<',';
        }
    }
    cout<<"]\n";
}

int Do(deque<int>& arr, string& p){
    int dir = 1;
    for(char c: p){
        if(c=='R'){
            dir *= -1;
        }
        else{
            if(arr.empty()) return 0;
            if(dir==1){ // 정방향
                arr.pop_front();
            }
            else{       // 역방향
                arr.pop_back();
            }
        }
    }
    return dir;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        string p;
        int n;
        deque<int> arr;
        cin>>p;
        cin>>n;
        if(n){
            char ch;
            cin>>ch;
            while(ch!=']'){
                int k;
                cin>>k;
                cin>>ch;
                arr.push_back(k);
            }
        }
        else{
            char str[3];
            cin>>str;
        }
        int result = Do(arr,p);
        if(result)      Print(arr, result);
        else            cout<<"error\n";
    }
}