#include <iostream>
#include<algorithm>
#include <vector>
#include <string>


using namespace std;

int main()
{
	int day, cnt;
	cin >> day >> cnt;

	int num;
	vector<int> weather(day);
	for (int i = 0; i < day; i++)
	{
		cin >> num;
		weather[i] = num;
	}

	int sum = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += weather[i];
	}
	int answer = sum;

	for (int i = cnt; i < day; i++)
	{
		sum += weather[i] - weather[i - cnt];
		answer = max(answer, sum);
	}
	cout << answer;
}

