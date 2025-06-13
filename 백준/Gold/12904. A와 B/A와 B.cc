#include <iostream>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string S, T;
	cin >> S >> T;

	string prevStr = T;
	while (true)
	{
		string newStr = prevStr.substr(0, prevStr.length() - 1);;
		if (prevStr.back() == 'B')
		{
			reverse(newStr.begin(), newStr.end());
		}
		prevStr = newStr;

		if (newStr.length() == S.length())
		{
			break;
		}
	}

	cout << !(S.compare(prevStr)) << endl;
}