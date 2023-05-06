#include <iostream>

using namespace std;

int main(){
    char str[101];
    cin>>str;
    int count = 0;
    for(int i=0; i<101; i++){
        char c = str[i];
        if(c=='\0') break;
        count++;
        int nextIdx = i+1;
        if(nextIdx > 100)  continue;
        if(c=='c'){
            if(str[nextIdx]=='-' || str[nextIdx]=='=')
                i++;
        }
        else if(c=='d'){
            if(str[nextIdx]=='-')   i++;
            else if(str[nextIdx]=='z'){
                if(str[nextIdx+1]=='=') i+=2;
            }
        }
        else if(c=='l' || c=='n'){
            if(str[nextIdx]=='j')   i++;
        }
        else if(c=='s' || c=='z'){
            if(str[nextIdx]=='=')   i++;
        }
    }
    cout<<count<<endl;
}