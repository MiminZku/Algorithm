#include <iostream>
using namespace std;

char arr[2188][2188];

void star(int rS, int rE, int cS, int cE){
    if(rS == rE){
        arr[rS][cS] = '*';
        return;
    }
    int len = (rE-rS+1)/3;
    for (int r = 0; r < 3; r++){
        for(int c = 0; c < 3; c++){
            if(r==1 && c==1)    continue;
            star(rS+r*len, rS+(r+1)*len-1, cS+c*len, cS+(c+1)*len-1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = ' ';
        }
    }
    
    star(1, n, 1, n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
}