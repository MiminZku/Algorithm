#include <iostream>
#include <stack>

using namespace std;

int n;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

    long long ans = 0;
    stack<pair<int, long long>> st;
    cin >> n;
    for (int i = 0, k; i < n + 1; ++i)
    {
        if (i == n)
        {
            k = 0;
        }
        else
        {
            cin >> k;
        }

        int l = i;
        while (!st.empty() && k < st.top().second)
        {
            l = st.top().first;
            ans = max(ans, (i - l) * st.top().second);
            st.pop();
        }
        st.push({ l, k });
    }

    cout << ans << '\n';
	
}