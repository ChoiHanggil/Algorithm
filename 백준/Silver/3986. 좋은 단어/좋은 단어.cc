#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
    int n, answer = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        stack<char> st;

        for (char c : s) {
            if (!st.empty() && st.top() == c) 
            {
                st.pop();
            }
            else 
            {
                st.push(c);
            }
        }

        if (st.empty()) 
        {
            answer++;
        }
    }

    cout << answer;

}
