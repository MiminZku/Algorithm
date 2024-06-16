#include <iostream>

using namespace std;

int n;
int arr[6];
int t, p;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    cin>>n;
    for(int i=0; i<6; ++i)  cin>>arr[i];
    cin>>t>>p;

    int tSum = 0;
    for(int i=0; i<6; ++i)
    {
        tSum += (arr[i]%t == 0) ? arr[i]/t : arr[i]/t + 1;
    }

    cout << tSum << '\n' << n/p << ' ' << n%p << endl;
}