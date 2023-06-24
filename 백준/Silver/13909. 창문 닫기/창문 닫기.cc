#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;;i++){
        if(i*i<=n && (i+1)*(i+1)>n){
            cout<<i<<endl;
            break;
        }
    }
}