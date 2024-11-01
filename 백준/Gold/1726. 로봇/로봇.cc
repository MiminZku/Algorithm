#include <iostream>
#include <queue>

using namespace std;

int m, n;
bool mat[101][101];
bool visited[101][101][5];

struct Node
{
	int row;
	int col;
	int dir;

	bool operator ==(const Node& other)
	{
		return row == other.row && col == other.col && dir == other.dir;
	}
};

Node src, des;

int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };

int BFS()
{
	int ret = -1;

	visited[src.row][src.col][src.dir] = true;
	queue<pair<Node, int>> q;
	q.push({ src, 0 });

	while (!q.empty())
	{
		Node cur = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (cur == des)
		{
			ret = dist;
			break;
		}

		vector<Node> nextNodes;
		if (1 == cur.dir)
		{
			for (int i = 1; i <= 3; ++i)
			{
				Node node = { cur.row, cur.col + i, cur.dir };
				if (node.col > n) break;
				if (mat[node.row][node.col]) break;
				nextNodes.push_back(node);
			}
			nextNodes.push_back(Node{ cur.row, cur.col, 3 });
			nextNodes.push_back(Node{ cur.row, cur.col, 4 });
		}
		else if (2 == cur.dir)
		{
			for (int i = 1; i <= 3; ++i)
			{
				Node node = { cur.row, cur.col - i, cur.dir };
				if (node.col < 1) break;
				if (mat[node.row][node.col]) break;
				nextNodes.push_back(node);
			}
			nextNodes.push_back(Node{ cur.row, cur.col, 3 });
			nextNodes.push_back(Node{ cur.row, cur.col, 4 });
		}
		else if (3 == cur.dir)
		{
			for (int i = 1; i <= 3; ++i)
			{
				Node node = { cur.row + i, cur.col, cur.dir };
				if (node.row > m) break;
				if (mat[node.row][node.col]) break;
				nextNodes.push_back(node);
			}
			nextNodes.push_back(Node{ cur.row, cur.col, 1 });
			nextNodes.push_back(Node{ cur.row, cur.col, 2 });
		}
		else if (4 == cur.dir)
		{
			for (int i = 1; i <= 3; ++i)
			{
				Node node = { cur.row - i, cur.col, cur.dir };
				if (node.row < 1) break;
				if (mat[node.row][node.col]) break;
				nextNodes.push_back(node);
			}
			nextNodes.push_back(Node{ cur.row, cur.col, 1 });
			nextNodes.push_back(Node{ cur.row, cur.col, 2 });
		}

		for (Node node : nextNodes)
		{
			if (visited[node.row][node.col][node.dir])	continue;
			visited[node.row][node.col][node.dir] = true;
			q.push({ node, dist + 1 });
		}
	}

	return ret;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> m >> n;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> mat[i][j];
		}
	}
	cin >> src.row >> src.col >> src.dir;
	cin >> des.row >> des.col >> des.dir;

	cout << BFS() << endl;
}