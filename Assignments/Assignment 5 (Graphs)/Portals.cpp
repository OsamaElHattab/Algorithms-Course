#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <climits>

using namespace std;

void INITIALIZE_SINGLE_SOURCE( vector<vector<pair<int, int>>>& adj_list, vector<int>& health,  int s) 
{
    health.assign(adj_list.size(), INT_MAX);
    health[s] = 0;
}

void RELAX( int u,  int v,  int w, vector<int>& health, priority_queue<pair<int, int>>& Q) 
{
    if ( health[v] >  health[u] + w)
    {
        health[v] = health[u] + w;
        Q.emplace(health[u] + w, v);
    }
}

vector<int> Dijkstra( vector<vector<pair<int, int>>>& adj_list,  int s) 
{
    vector<int> health;
    priority_queue<pair<int, int>> Q;
    INITIALIZE_SINGLE_SOURCE(adj_list, health, s);
    Q.emplace(0, s);
    while (!Q.empty()) 
    {
        int curr_health = Q.top().first;
        int curr_city = Q.top().second;
        Q.pop();
        if (curr_health > health[curr_city]) 
            continue;
        for (auto& next : adj_list[curr_city]) 
        {
            RELAX(curr_city, next.first, next.second, health, Q);
        }
    }
    return health;
}

int main() 
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> adj_list(n);
    for (int i = 0; i < m; i++) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back(make_pair(v, w));
    }

    vector<int> health = Dijkstra(adj_list, s);

    int reachable = 0;
    int maxHealth = 0;
    for (int i = 0; i < n; i++) 
    {
        if (health[i] != INT_MAX)
            reachable++;
        maxHealth = max(maxHealth, health[i]);
    }
    cout << reachable << " " << maxHealth << endl;
    return 0;
}