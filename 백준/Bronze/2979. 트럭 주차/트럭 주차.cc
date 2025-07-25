#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> fee;
	int cost;
	for (int i = 0; i < 3; i++)
	{
		cin >> cost;
		fee.push_back(cost);
	}

	vector<int> cnt(101, 0);
	int in, out;
	for (int i = 0; i < 3; i++)
	{
		cin >> in;
		cin >> out;
		for (int i = in; i < out; i++)
		{
			cnt[i]++;
		}
	}

	int total{ 0 };
	for (auto e : cnt)
	{
		if (e == 1)
		{
			total += fee[0];
		}
		else if(e == 2)
		{ 
			total += (fee[1]*e);
		}
		else if (e == 3)
		{
			total += (fee[2]*e);
		}
		
	}


	cout << total << endl;

}

