#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;
unordered_set<string> visited;
string board = "";
string goal = "123456780";

int dr[] = { 0,0,-1,1 };
int dc[] = { -1,1,0,0 };

int BFS()
{
	int mtIdx;
	for (int i = 0; i < 9; ++i)
	{
		if (board[i] == '0')
		{
			mtIdx = i;
		}
	}
	queue<pair<string, pair<int, int>>> q;
	q.push({ board, {0, mtIdx} });
	visited.insert(board);

	while (!q.empty())
	{
		string cur = q.front().first;
		int dist = q.front().second.first;
		int mtIdx = q.front().second.second;
		q.pop();

		if (cur.compare(goal) == 0)
		{
			return dist;
		}

		int mtR = mtIdx / 3;
		int mtC = mtIdx % 3;
		for (int i = 0; i < 4; ++i)
		{
			int nr = mtR + dr[i];
			int nc = mtC + dc[i];
			if (nr < 0 || nc < 0 || nr > 2 || nc > 2)	continue;
			string newBoard = cur;
			int nIdx = nr * 3 + nc;
			int tmp = newBoard[mtIdx];
			newBoard[mtIdx] = newBoard[nIdx];
			newBoard[nIdx] = tmp;
			if (visited.find(newBoard) != visited.end()) continue;
			visited.insert(newBoard);
			q.push({ newBoard, {dist + 1, nIdx} });
		}
	}

	return -1;
}

int main()
{
	char ch;
	for (int i = 0; i < 9; ++i)
	{
		cin >> ch;
		board += ch;
	}

	cout << BFS() << endl;
}