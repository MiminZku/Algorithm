#include <iostream>
#include <string>
using namespace std;

string num;

int main()
{
	cin.tie(nullptr); ios::sync_with_stdio(false);
	cin >> num;

	if (num.size() == 2)
	{
		cout << (num[0] - '0') + (num[1] - '0') << endl;
	}
	else if (3 == num.size())
	{
		if('0' == num[1])
			cout << stoi(num.substr(0, 2)) + (num[2] - '0') << endl;
		else
			cout << stoi(num.substr(1, 2)) + (num[0] - '0') << endl;

	}
	else
	{
		cout << stoi(num.substr(0, 2)) + stoi(num.substr(2, 2)) << endl;
	}

}