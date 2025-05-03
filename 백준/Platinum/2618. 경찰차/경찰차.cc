#include <iostream>
#include <memory.h>

using namespace std;

#define Y first
#define X second

int n, w;
pair<int, int> affairs[1000];
int memo[1002][1002];
int trace[1002][1002];

int Dist(int src, int des)
{
	if (src == -1)
	{
		return abs(affairs[des].Y - 1) + abs(affairs[des].X - 1);
	}

	if (src == -2)
	{
		return abs(affairs[des].Y - n) + abs(affairs[des].X - n);
	}

	return abs(affairs[src].Y - affairs[des].Y) + abs(affairs[src].X - affairs[des].X);
}

int Recur(int p1, int p2)
{
	int next = max(p1, p2) + 1;
	if (next == w)
	{
		return 0;
	}

	int& memoRef = memo[p1 + 2][p2 + 2];
	if (memoRef != -1)
	{
		return memoRef;
	}
	
	// 경찰차 1 보내는 경우
	int t1 = Dist(p1, next) + Recur(next, p2);

	// 경찰차 2 보내는 경우
	int t2 = Dist(p2, next) + Recur(p1, next);

	trace[p1 + 2][p2 + 2] = t1 < t2 ? 1 : 2;
	return memoRef = min(t1, t2);
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	memset(memo, -1, sizeof(memo));

	cin >> n >> w;
	for (int i = 0, x, y; i < w; ++i)
	{
		cin >> x >> y;
		affairs[i].Y = y;
		affairs[i].X = x;
	}

	cout << Recur(-1, -2) << endl;
	for (int i = 0, p1 = -1, p2 = -2; i < w; ++i)
	{
		int res = trace[p1 + 2][p2 + 2];
		cout << res << '\n';
		if (res == 1)
		{
			p1 = i;
		}
		else
		{
			p2 = i;
		}
	}
}