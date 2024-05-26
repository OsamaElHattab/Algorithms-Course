#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define ll long long
vector < ll > health;
vector < ll > weapons;
vector<pair<ll, ll>> dp(10500, pair<ll, ll>(-1 , -1));
ll N, M, temp, temp2;
//vector<pair<ll, ll>>& dp

pair<ll, ll> bruteForce(ll health)               // < h,w>
{
    if (dp[health].first < 0)
    {
        if (health == 0)
        {
            dp[health] = { health, 0 };
            return dp[health];
        }

        pair<ll, ll> minimum1(LLONG_MAX, LLONG_MAX);
        pair<ll, ll> minimum2(LLONG_MAX, LLONG_MAX);
        bool flag1 = 0;
        bool flag2 = 0;

        pair<ll, ll> output;
        for (int i = 0; i < M; i++)
        {
            if (weapons[i] == 0)
            {
                continue;
            }
            if (health >= weapons[i])
            {
                pair<ll, ll> temp = bruteForce(health - weapons[i]);
                output.first = temp.first;
                output.second = temp.second + 1;
            }
            else
            {
                output = { health, 0 };
            }
                
            if (output.first == 0 && output.second < minimum1.second)
            {
                minimum1.first = output.first;
                minimum1.second = output.second;
                flag1 = 1;
            }
            else if ((output.second) < minimum2.second || (((output.second) == minimum2.second) && (output.first) < minimum2.first))
            {
                minimum2.first = (output.first);
                minimum2.second = (output.second);
                flag2 = 1;
            }
        }

        if (flag1)
        {
            dp[health] = minimum1;
        }
        else
        {
            dp[health] = minimum2;
        }
    }

    return dp[health];

}

int main() 
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        health.push_back(temp);
    }
    cin >> M;
    bool notzero = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> temp2;
        weapons.push_back(temp2);
        if (temp2)
            notzero = 1;
    }
    if (notzero == 0)
    {
        for (int i = 0; i < N; i++)
        {
            cout << health[i] << " " << 0<< endl;
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            pair<ll, ll> output = bruteForce(health[i]);
            cout << output.first << " " << output.second << endl;
        }
    }
    

    return 0;
}
