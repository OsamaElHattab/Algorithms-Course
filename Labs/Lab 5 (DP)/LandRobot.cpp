#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;

long long n, m;
vector <vector <long long>> gold(1050, vector <long long>(1050));
vector <vector <long long>> dp(1050, vector <long long>(1050, -1));

long long GoldCollector(long long i, long long j)
{
    if (i > n - 1 || j > m - 1)
        return LONG_MIN;
    if (i == n - 1 && j == m - 1)
        return dp[i][j] = gold[i][j];
    else
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        else {
            return dp[i][j] = gold[i][j] +
                max(GoldCollector(i + 1, j), max(GoldCollector(i, j + 1), GoldCollector(i + 1, j + 1)));
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> gold[i][j];
        }
    }
    cout << GoldCollector(0, 0) << endl;
    return 0;
}