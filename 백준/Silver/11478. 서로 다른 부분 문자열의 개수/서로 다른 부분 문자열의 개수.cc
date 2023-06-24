#include <iostream>
#include <set>
#include <string>

using namespace std;

string str;
int strLen;

int main(){
    cin>>str;
    strLen = str.length();
    set<string> isExist;

    for(int i=1; i<=strLen; i++){
        for(int j=0; j<=strLen-i; j++){
            string subStr = str.substr(j,i);
            isExist.insert(subStr);
        }
    }

    cout<<isExist.size()<<endl;
}