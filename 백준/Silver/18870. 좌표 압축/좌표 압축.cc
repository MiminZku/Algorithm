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
    int arr[n]; int org[n];
    for(int i = 0; i<n ; i++){
        int x;
        scanf("%d", &x);
        arr[i] = x;
        org[i] = x;
    }
    sort(arr, arr+n);
    vector<int> de_duplicate_arr;
    de_duplicate_arr.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            de_duplicate_arr.push_back(arr[i]);
        }
    }

    for(int i: org){
        printf("%d ",BinarySearch(de_duplicate_arr, 0, de_duplicate_arr.size()-1, i));
    }
    printf("\n");
    return 0;
}