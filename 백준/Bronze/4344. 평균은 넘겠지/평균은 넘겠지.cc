#include <iostream>
#include <vector>

using namespace std;

void Solve(const vector<int>& arr, const int& n, const int& sum){
    double avg = (double)sum/n;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(arr[i] > avg)    cnt++;
    }
    int res = cnt*1000000/n;
    if(res%10 >= 5)    res+=10;
    res/=10;
    cout<<res/1000<<'.';
    int resArr[3];
    for(int i=2; i>=0; i--){
        resArr[i] = res%10;
        res/=10;
    }
    for(int i=0; i<3; i++)  cout<<resArr[i];
    cout<<"%\n";
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int c;
    cin>>c;
    while(c--){
        int n,k,sum=0;
        cin>>n;
        vector<int> arr;
        for(int i=0; i<n; i++){
            cin>>k;
            sum+=k;
            arr.push_back(k);
        }
        Solve(arr, n, sum);
    }
}