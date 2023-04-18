#include <iostream>

int main(){
    int n, m;
    std::cin>>n>>m;

    int plans[m][3];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 3; j++){
            std::cin>>plans[i][j];
        }
    }

    int res[n] = {0,};
    for(int i =0; i < m; i++){
        for(int j = plans[i][0]; j <= plans[i][1]; j++){
            res[j-1] = plans[i][2];
        }
    }

    for (int i = 0; i < n ; i++){
        std::cout<<res[i]<<' ';
    }std::cout<<'\n';
}