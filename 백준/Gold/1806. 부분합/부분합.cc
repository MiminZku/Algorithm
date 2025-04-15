#include <iostream>

using namespace std;

int n, s;
int arr[100000];

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i=0; i<n; ++i)
    {
        cin >> arr[i];
    }

    int l = 0, r = 0;
    int sum = arr[0];
    int ans = 111111;
    while(r < n && l <= r)
    {
        if(sum < s)
        {
            r++;
            sum += arr[r];
        }
        else
        {
            ans = min(ans, r - l + 1);
            sum -= arr[l];
            l++;
        }
    }

    if(ans > 100000)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}