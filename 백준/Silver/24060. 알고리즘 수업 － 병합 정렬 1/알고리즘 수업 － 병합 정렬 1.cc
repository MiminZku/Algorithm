#include <iostream>

using namespace std;

int n;
int k;
int arr[500000];
int cnt;

void Merge(int s, int e)
{
    int mid = (s + e) / 2;
    int len = e - s + 1;
    int tmp[len + 1];
    int idx = 0;
    int l = s;
    int r = mid + 1;
    while(l <= mid && r <= e)
    {
        if(arr[l] <= arr[r])
        {
            tmp[idx++] = arr[l++];
        }
        else
        {
            tmp[idx++] = arr[r++];
        }
    }
    while(l <= mid)
    {
        tmp[idx++] = arr[l++];
    }
    while(r <= e)
    {
        tmp[idx++] = arr[r++];
    }

    for(int i = 0; i < len; ++i)
    {
        arr[s + i] = tmp[i];
        ++cnt;
        if(k == cnt)
        {
            cout << tmp[i] << endl;
        }
    }
}

void MergeSort(int s, int e)
{
    if(s == e)  return;
    int mid = (s + e) / 2;
    MergeSort(s, mid);
    MergeSort(mid + 1, e);
    Merge(s, e);
}


int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> n;
    cin >> k;
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
    }

    MergeSort(0, n - 1);

    if(cnt < k)
    {
        cout << -1 << endl;
    }
}