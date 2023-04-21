#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n;

int BinarySearch(vector<int>& vec, int start, int end, int target){
    if (start == end){
        if(target==vec[start]){
            return start;
        }
        return -1;
    }
    int mid = (start+end)/2;
    int idx;
    if (vec[mid] < target){
        idx = BinarySearch(vec, mid+1, end, target);
    }
    else{
        idx = BinarySearch(vec, start, mid, target);
    }
    return idx;
}

int main(){
    scanf("%d",&n);
    vector<int> sorted; int org[n];
    for(int i = 0; i<n ; i++){
        int x;
        scanf("%d", &x);
        org[i] = x;
        sorted.push_back(x); 
    }
    sort(sorted.begin(), sorted.end());
    vector<int> uniq_arr(sorted);
    uniq_arr.erase(unique(uniq_arr.begin(),uniq_arr.end()),uniq_arr.end());

    for(int i: org){
        printf("%d ",BinarySearch(uniq_arr, 0, uniq_arr.size()-1, i));
    }
    printf("\n");
    return 0;
}