#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int num=1,den=1;    // 분자, 분모
    int sum = 2;
    int i=1, line = 1;
    while(true){
        if(n==i++)    break;
        if(line % 2){
            num--;
            den++;
            if(num<1){
                num = 1;
                den = sum;
                sum++;
                line++;
            }
        }
        else{
            num++;
            den--;
            if(den<1){
                num = sum;
                den = 1;
                sum++;
                line++;
            }
        }
    }
    cout<<num<<'/'<<den<<endl;
}