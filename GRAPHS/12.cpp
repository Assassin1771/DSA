// SHORTEST PATH IN UNDIRECTED & UNWEIGHTED GRAPH

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void check(vector<int> adj[], int v, int s)
{
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;

    queue<int> q;
    q.push(s);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto it : adj[curr])
        {
            if (dist[it] > dist[curr] + 1)
            {
                dist[it] = dist[curr] + 1;
                q.push(it);
            }
        }
    }

    for (auto it : dist)
    {
        cout << it << endl;
    }
}

int main()
{
    vector<int> adj[5];
    int n = 5;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    check(adj, n, 0);

    return 0;
}