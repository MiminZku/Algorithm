#include <iostream>

using namespace std;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int xMax=-10000, xMin=10000, yMax=-10000, yMin=10000;
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a>xMax)    xMax = a;
        if(a<xMin)    xMin = a;
        if(b>yMax)    yMax = b;
        if(b<yMin)    yMin = b;
    }
    cout<<(xMax-xMin)*(yMax-yMin)<<endl;
}