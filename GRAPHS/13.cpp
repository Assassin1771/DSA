// SHORTEST PATH IN UNDIRECTED & WEIGHTED GRAPH (DIJKSTRA ALGO)

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int a, int b, int wt)
{
    adj[a].push_back({b, wt});
    adj[b].push_back({a, wt});
}

void check(vector<pair<int, int>> adj[], int v, int s)
{
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});

    while (pq.empty() == false)
    {
        int curr = pq.top().first;
        int dist1 = pq.top().second;

        pq.pop();

        for (auto it : adj[curr])
        {
            int curr1 = it.first;
            int dist_curr = it.second;

            if (dist[curr1] > dist_curr + dist1)
            {
                dist[curr1] = dist_curr + dist1;
                pq.push({curr1, dist_curr + dist1});
            }
        }
    }

    for (auto it : dist)
        cout << it << endl;
}

int main()
{
    vector<pair<int, int>> adj[5];
    int n = 5;

    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 10);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 3, 4, 1);

    check(adj, n, 0);

    return 0;
}