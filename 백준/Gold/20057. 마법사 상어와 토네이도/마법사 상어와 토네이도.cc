#include <iostream>

using namespace std;

enum Dir
{
	Left,
	Down,
	Right,
	Up
};

int n;
int mat[500][500];

// Left 방향 기준
int dy[] = { -1, 1, -2, 2,  0, -1, 1, -1,  1,  0 };
int dx[] = {  1, 1,  0, 0, -2,  0, 0, -1, -1, -1 };
int dv[] = {  1, 1,  2, 2,  5,  7, 7, 10, 10, -1 };

int dr[] = { 0, 1, 0, -1 };
int dc[] = { -1, 0, 1, 0 };

void Tornado(int r, int c, Dir dir, int goalCnt, int cnt, int con)
{
	if (r == 1 && c == 1)
	{
		return;
	}

	int val = mat[r + dr[dir]][c + dc[dir]];
	mat[r + dr[dir]][c + dc[dir]] = 0;

	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		int nv = val * dv[i] / 100;

		if (dir == Left)
		{
			nr += dy[i];
			nc += dx[i];
		}
		else if (dir == Down)
		{
			nr -= dx[i];
			nc += dy[i];
		}
		else if (dir == Right)
		{
			nr += dy[i];
			nc -= dx[i];
		}
		else if (dir == Up)
		{
			nr += dx[i];
			nc += dy[i];
		}
		
		sum += max(0, nv);
		if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
		mat[nr][nc] += (i == 9) ? (val - sum) : nv;
	}

	cnt++;
	Dir newDir = dir;

	// 목표 칸수만큼 직선으로 이동 했으면 방향 꺾음
	if (goalCnt == cnt)
	{
		con++;
		cnt = 0;
		newDir = (Dir)((dir + 1) % 4);
	}
	// 목표 칸수만큼 2번 이동했으면 목표칸수 1 증가시킴
	if (con == 2)
	{
		con = 0;
		goalCnt++;
	}

	Tornado(r + dr[dir], c + dc[dir], newDir, goalCnt, cnt, con);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> mat[i][j];
			ans += mat[i][j];
		}
	}

	Tornado((1 + n) / 2, (1 + n) / 2, Left, 1, 0, 0);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ans -= mat[i][j];
		}
	}

	cout << ans << endl;
}