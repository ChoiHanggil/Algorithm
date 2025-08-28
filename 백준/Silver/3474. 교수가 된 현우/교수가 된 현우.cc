
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include <limits>
#include <unordered_set>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int ret = 0;
		cin >> n;
		for(int i = 5; n / i >= 1; i *= 5) 
		{
			ret += n / i;
		}
		cout << ret << '\n';
			
	}

}


