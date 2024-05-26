#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;



int main()
{
    map <int, multiset<int>> mp; //penalties are the keys
    vector <int> deadlines;
    int N, temp, deadline, index_end;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        deadlines.push_back(temp);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        //mp.insert({ temp, deadlines[i] });
        mp[temp].insert(deadlines[i]);
    }

    vector <int> output((N + 1), 0);
    long long totalPenalty = 0;
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        for (auto itr = (it->second).begin(); itr != (it->second).end(); itr++)
        {
            deadline = *itr;
            while (output[deadline] && deadline)
            {
                deadline--;
            }
            if (deadline)
            {
                output[deadline] = *itr;
                continue;
            }

            totalPenalty += it->first;
            index_end = N;
            while (output[index_end] && index_end)
            {
                index_end--;
            }
            if (index_end)
            {
                output[index_end] = *itr;
            }
        }
    }

    /*for (int i = 1; i < N + 1; i++) {
        cout << output[i];
    }*/

    cout << totalPenalty;
    return 0;
}
