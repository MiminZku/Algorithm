#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n;
int difficulties[31];
vector<int> sortedArr;

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    if(!n){
        cout<<0<<endl;
        return 0;
    }
    int cut = round(n*0.15);
    int num = n-2*cut;
    while(n--){
        int k;
        cin>>k;
        difficulties[k]++;
    }
    int sum = 0;
    for(int i=1; i<31; i++){
        if(!difficulties[i])    continue;
        while(difficulties[i]--)
            sortedArr.push_back(i);
    }
    for(int i=cut; i<num+cut; i++){
        sum+=sortedArr[i];
    }
    cout<<round((double)sum/num)<<endl;
}