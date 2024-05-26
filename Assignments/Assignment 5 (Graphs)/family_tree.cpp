#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<list>
using namespace std;


void dfs_visit(vector <vector<int>>& adj_list, vector <bool>& isvisted, list<int>& lis, int i)
{
    isvisted[i] = true;
    for (int j : adj_list[i])
    {
        if (!isvisted[j])
        {
            dfs_visit(adj_list, isvisted, lis, j);
        }
    }
    lis.push_front(i);
}

void dfs(vector <vector<int>>& adj_list, vector <bool>& isvisted, list<int>& lis)
{
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (!isvisted[i])
        {
            dfs_visit(adj_list, isvisted, lis, i);
        }
    }
}


int main()
{
    int  n, a, b;
    cin >> n;
    vector <vector<int>>adj_list(n);
    vector <bool>isvisted(n, false);
    list<int> lis;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a != -1)
            adj_list[a].push_back(i);
        if (b != -1)
            adj_list[b].push_back(i);
    }

    dfs(adj_list, isvisted, lis);

    while (!lis.empty())
    {
        cout << lis.front() << " ";
        lis.pop_front();
    }

    return 0;
}
