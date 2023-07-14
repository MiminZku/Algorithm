#include <iostream>

using namespace std;


int n;
int result;

bool rowCheck[15];
bool rightDown[30];
bool rightUp[30];

void Solve(int col){
    if(col == n){
        result++;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<board[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return;
    }

    for(int row=0; row<n; row++){
        if(rowCheck[row] || rightDown[n+col-row] || rightUp[col+row])  continue;
        rowCheck[row] = true;
        rightDown[n+col-row] = true;
        rightUp[col+row] = true;

        Solve(col+1);

        rowCheck[row] = false;
        rightDown[n+col-row] = false;
        rightUp[col+row] = false;
    }
}

int main(){
    cin>>n;

    Solve(0);

    if(n==1)    result = 1;
    cout<<result<<endl;
}