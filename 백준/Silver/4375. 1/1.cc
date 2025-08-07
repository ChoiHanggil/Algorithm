#include <iostream>
//#include <vector>
//#include <map>
//#include <unordered_map>
//#include<string>
//#include<algorithm>
//#include<stack>
#include<cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		long long a = 1, cnt = 1;

		while (a % n != 0)
		{
			a = (a * 10) + 1;
			a %= n;
			cnt++;
		}

		cout << cnt << endl;
	}
}
