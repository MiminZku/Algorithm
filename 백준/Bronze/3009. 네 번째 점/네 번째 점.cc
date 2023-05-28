#include <iostream>
using namespace std;

bool bitX[1001];
bool bitY[1001];

int main(){
    int n = 3;
    while(n--){
        int a,b;
        cin>>a>>b;
        bitX[a] = !bitX[a];
        bitY[b] = !bitY[b];
    }
    for(int i=1; i<1001; i++){
        if(bitX[i]){
            cout<<i<<' ';
            break;
        }
    }
    for(int i=1; i<1001; i++){
        if(bitY[i]){
            cout<<i<<endl;
            break;
        }
    }    
}