#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int N, M;
unordered_map<string, vector<pair<string, bool>>> childs;

void DFS(string folderName, unordered_set<string>& fileCnt, int& fileTotalCnt)
{
	for (auto child : childs[folderName])
	{
		if (child.second)	// folder
		{
			DFS(child.first, fileCnt, fileTotalCnt);
		}
		else
		{
			fileCnt.insert(child.first);
			fileTotalCnt++;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin.ignore();

	string P, F, C;
	for (int i = 0; i < N + M; ++i)
	{
		cin >> P >> F >> C;
		childs[P].push_back({ F, C.compare("0") });		
	}
	cin.ignore();

	int Q;
	cin >> Q;
	cin.ignore();
	string path;
	while (Q--)
	{
		cin >> path;
		while (true)
		{
			auto idx = path.find('/');
			if (idx == string::npos)
			{
				break;
			}
			path = path.substr(idx + 1, path.length() - idx);
		}

		unordered_set<string> fileSet;
		int totalCnt = 0;
		
		DFS(path, fileSet, totalCnt);

		cout << fileSet.size() << ' ' << totalCnt << '\n';
	}
}