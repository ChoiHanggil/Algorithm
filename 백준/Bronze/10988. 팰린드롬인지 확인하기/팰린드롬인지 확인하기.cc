#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int main()
{
	string s;
	cin >> s;
	string r = s;
	reverse(s.begin(), s.end());
	
	cout << (r == s);
}

