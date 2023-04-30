#include <iostream>
#include <vector>
#include <string>
using namespace std;

void RadixSort(vector<string>& lst, int length){   // 기수 정렬
    for(int i=length-1; i>=0; i--){
        vector<string> temp[26];
        for(string str: lst){
            temp[(int)str[i]-97].push_back(str);
        }
        lst.clear();
        for(vector<string> str_arr: temp){
            for(string str: str_arr){
                lst.push_back(str);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> arr[51]; //arr[i] : 길이가 i인 문자열들의 리스트
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        arr[str.length()].push_back(str);
    }
    for(int i=1; i<=50; i++){
        if(arr[i].empty())  continue;
        RadixSort(arr[i], i);
        cout<<arr[i][0]<<"\n";
        for(int j=1; j<arr[i].size(); j++){
            if(arr[i][j] == arr[i][j-1])    continue;
            cout<<arr[i][j]<<"\n";
        }
    }
}