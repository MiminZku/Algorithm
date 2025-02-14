#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    cin >> n;
    int arr[5] = {};
    for(int i=1; i<=n; ++i)
    {

        for(int j=0; j<5; ++j)
        {
            cin >> arr[j]; 
        }
        sort(arr, arr + 5);
        cout << "Case #" << i << ": " << arr[4] << '\n';
    }
}