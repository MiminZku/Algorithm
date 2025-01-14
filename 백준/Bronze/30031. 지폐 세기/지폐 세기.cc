#include <iostream>

using namespace std;

int arr[4] = {1000, 5000, 10000, 50000};
int cnt[4] = {};
int n;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        int w, h;
        cin >> w >> h;
        if(w == 136) cnt[0]++;
        else if(w == 142) cnt[1]++;
        else if(w == 148) cnt[2]++;
        else cnt[3]++;
    }
    int sum = 0;
    for(int i=0; i<4; ++i)
    {
        sum += cnt[i] * arr[i];
    }
    cout << sum << endl;
}