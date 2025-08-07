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
	long long a, b, c;

	cin >> a >> b >> c;

	long long answer = 1;
	a %= c;

	while (b > 0)
	{
		if (b & 1)
		{
			answer = (answer * a) % c;
		}
		a = (a * a) % c;
		b >>= 1;
	}
	
	cout << answer;
}
