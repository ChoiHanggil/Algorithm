
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
#include <iomanip>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	
	int i = 666;
	while (n > 0)
	{
		if (to_string(i).find("666") != string::npos) n--;
		i++;
	}

	cout << i-1 << '\n';
	
}


