#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;
	str.append(" ");

	vector<int> numList;
	vector<char> opList;
	string temp = "";
	for (char ch : str)
	{
		if (ch >= '0' && ch <= '9')
		{
			temp.append(1, ch);
			continue;
		}

		if (ch == '+' || ch == '-')
		{
			opList.push_back(ch);
		}
	
		int num = stoi(temp);
		numList.push_back(num);
		temp = "";
	}

	for (int i = 0; i < opList.size(); ++i)
	{
		if (opList[i] != '+')	continue;
		
		numList[i] += numList[i + 1];
		numList.erase(numList.begin() + i + 1);

		opList.erase(opList.begin() + i);
		--i;
	}

	int ans = numList[0];
	for (int i = 1; i < numList.size(); ++i)
	{
		ans -= numList[i];
	}

	cout << ans << endl;
}