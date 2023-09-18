#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> arr;

void MergeSort(int start, int end)
{
    if(start == end)    return;
    int mid = (start + end) / 2;
    MergeSort(start, mid);
    MergeSort(mid+1, end);

    int leftIdx = start;
    int rightIdx = mid+1;
    vector<pair<int,int>> tempArr;
    while(leftIdx <= mid && rightIdx <= end)
    {
        if(arr[leftIdx].first < arr[rightIdx].first)
        {
            tempArr.push_back(arr[leftIdx++]);
        }
        else if(arr[leftIdx].first == arr[rightIdx].first)
        {
            if(arr[leftIdx].second < arr[rightIdx].second)
            {
                tempArr.push_back(arr[leftIdx++]);
            }
            else
            {
                tempArr.push_back(arr[rightIdx++]);
            }
        }
        else
        {
            tempArr.push_back(arr[rightIdx++]);
        }
    }
    while(leftIdx <= mid)   tempArr.push_back(arr[leftIdx++]);
    while(rightIdx <= end)  tempArr.push_back(arr[rightIdx++]);

    for(int i = start, idx = 0; i <= end ; i++, idx++)
    {
        arr[i] = tempArr[idx];
    }
}

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin>>n;
    arr.resize(n);
    for(int i=0; i<n; i++)  cin>>arr[i].first>>arr[i].second;

    MergeSort(0, n-1);

    for(int i=0; i<n; i++)  cout<<arr[i].first<<' '<<arr[i].second<<'\n';    
}