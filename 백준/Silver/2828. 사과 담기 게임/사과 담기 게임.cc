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
    int m, n, j;
    cin >> m >> n >> j;

    int ret = 0;

    int start = 0;
    int end = n - 1;


    for (int i = 0; i < j; i++)
    {
        int apple;
        cin >> apple;
        int a = apple - 1;
        if (start >= a && end <= a)
        {
            continue;
        }
        if (a > end)
        {
            while (a > end)
            {
                start++;
                end++;
                ret++;
            }
        }
        else if (a < start)
        {
            while (a < start)
            {
                start--;
                end--;
                ret++;
            }
        }
    }

    cout << ret;
}


