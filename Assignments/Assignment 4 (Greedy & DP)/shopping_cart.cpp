#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long
vector < vector<ll> > input;
vector < vector<ll> > dp(25, vector <ll>(410, -1));
ll B, T, N, temp, min_alt, min_path;


ll bruteForce(ll type , ll remainder)
{
    if (type >= (T-1) )
    {
        return 0;
    }
    ll maximum = LLONG_MIN;
    ll output = LLONG_MIN;
    for (int i = 0; i < input[type+1].size() ; i++)
    {
        maximum = max(maximum , input[type + 1][i] + bruteForce(type+1 , remainder- input[type+1][i]) );
        if (maximum <= B)
        {
            output = max(maximum, output);
        }
    }
    return output;
}

ll dynamicP(ll type, ll remainder)
{
    if (remainder < 1)
    {
        return 0;
    }
    if (dp[type + 1][remainder] < 0)
    {
        if (type >= (T - 1))
        {
            dp[type + 1][remainder] = 0;
        }
        else
        {
            ll maximum = LLONG_MIN;
            ll output = LLONG_MIN;
            for (int i = 0; i < input[type + 1].size(); i++)
            {
                maximum = input[type + 1][i] + dynamicP(type + 1, remainder - input[type + 1][i]);
                if (maximum <= remainder)
                {
                    output = max(maximum, output);
                }
            }
            dp[type + 1][remainder] = output;
        }
    }
    return dp[type + 1][remainder];
}

int main()
{
    cin >> B >> T;
    min_path = 0;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        input.push_back(vector<ll>());
        min_alt = LLONG_MAX;
        for (int j = 0; j < N; j++)
        {
            cin >> temp;
            input[i].push_back(temp);
            min_alt = min(min_alt, temp);
        }
        min_path += min_alt;
    }

    if (min_path > B)
        cout << "no solution";
    else
        cout << dynamicP(-1, B);

    return 0;
}
