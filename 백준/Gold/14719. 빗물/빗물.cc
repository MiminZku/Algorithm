#include <iostream>

using namespace std;

int h, w;
int blocks[501];

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> h >> w;
    for(int i=0; i<w; ++i)
    {
        cin >> blocks[i];
    }

    int ans = 0;
    for(int i=1; i<=h; ++i)
    {
        for(int j=0, k=-1; j<w; ++j)
        {
            if(blocks[j] >= i)
            {
                if(k >= 0)
                {
                    ans += j - k - 1;
                }
                k = j;
            }
        }
    }

    cout << ans << endl;
}