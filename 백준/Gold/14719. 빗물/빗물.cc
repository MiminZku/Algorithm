#include <iostream>

using namespace std;

int h, w;
int arr[555];
int preMax[555];
int sufMax[555];
int ans;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin >> h >> w;
    
    for (int i = 1; i <= w; ++i)
    {
        cin >> arr[i];
        ans -= arr[i];  // 창고 다각형에서 블록 넓이 제외
    }

    for (int i = 1; i <= w; ++i)
    {
        preMax[i] = max(preMax[i - 1], arr[i]);
    }
    for (int i = w; i >= 1; --i)
    {
        sufMax[i] = max(sufMax[i + 1], arr[i]);
    }

    for (int i = 1; i <= w; ++i)
    {
        ans += min(preMax[i], sufMax[i]);
    }
    cout << ans << endl;
}