#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
unordered_set<int> s;

int main()
{
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cin >> n;
    int i;
    while(n--)
    {
        cin >> i;
        s.insert(i);
    }
    cin >> m;
    while(m--)
    {
        cin >> i;
        cout << (s.find(i) != s.end()) << '\n';
    }
}