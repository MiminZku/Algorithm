#include <iostream>
#include <deque>

using namespace std;

int n, k;
int arr[201];
bool isRobot[201];
deque<int> robot;
int cnt;

void Rotate()
{
	int temp = arr[2 * n];
	for (int i = 2 * n; i > 1; --i)
	{
		arr[i] = arr[i - 1];
	}
	arr[1] = temp;

	for (int i = n; i > 1; --i)
	{
		isRobot[i] = isRobot[i - 1];
	}
	isRobot[1] = false;
	isRobot[n] = false;
}

void RobotMove()
{
	for (int i = n - 1; i > 0; --i)
	{
		if (isRobot[i] == false		||
			isRobot[i + 1] == true	||
			arr[i + 1] <= 0)	continue;

		arr[i + 1]--;
		isRobot[i] = false;
		isRobot[i + 1] = true;
		if (arr[i + 1] == 0)
		{
			cnt++;
		}
	}
}

void PutRobot()
{
	if (arr[1] > 0)
	{
		isRobot[1] = true;
		arr[1]--;
		if (arr[1] == 0)
		{
			cnt++;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= 2 * n; ++i)
	{
		cin >> arr[i];
	}

	int step = 0;
	while (true)
	{
		step++;
		Rotate();
		RobotMove();
		PutRobot();
		if (cnt >= k)
		{
			break;
		}
	}

	cout << step << endl;
}