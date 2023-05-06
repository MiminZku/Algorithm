#include <iostream>

using namespace std;

int main(){
    char* mat[5];
    for(int i=0; i<5; i++){
        char* str = new char[16]();
        cin>>str;
        mat[i] = str;
    }
    for(int j=0; j<15; j++){
        for(int i=0; i<5; i++){
            if(!mat[i][j])    continue;
            cout<<mat[i][j];
        }
    }
}