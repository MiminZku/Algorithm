#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n;
string arr[20000];
unordered_map<string, int> dict;
vector<string> prefixArr;

bool isPrefix(const string& str, const string& prefix)
{
	if (prefix.length() == 0)	return true;
	if (str.length() < prefix.length())	return false;

	for (int i = 0; i < prefix.length(); ++i)
	{
		if (str[i] != prefix[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);

	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];

		string temp = "";
		for (int j = 0; j < arr[i].length(); ++j)
		{
			temp.append(1, arr[i][j]);
			if (dict.find(temp) == dict.end())
			{
				prefixArr.push_back(temp);
			}
			dict[temp]++;
		}
	}

	string ansPrefix = "";
	for (string str : prefixArr)
	{
		if (dict[str] < 2)	continue;
		
		if (str.length() > ansPrefix.length())
		{
			ansPrefix = str;
		}
	}

	for (int i = 0, cnt = 0; i < n && cnt < 2; ++i)
	{
		if (isPrefix(arr[i], ansPrefix))
		{
			cout << arr[i] << endl;
			cnt++;
		}
	}
}