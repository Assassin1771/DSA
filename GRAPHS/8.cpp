//TOPO SORT USING DFS

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
}

void topo(vector<int> adj[], vector<int> &vis, stack<int> &s, int node)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (vis[it] == 0)
        {
            vis[it] == 1;
            topo(adj, vis, s, it);
        }
    }

    s.push(node);
}

void find(vector<int> adj[], int v)
{
    vector<int> vis(v, 0);
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            topo(adj, vis, s, i);
        }
    }

    vector<int> topo;
    while (!s.empty())
    {
        topo.push_back(s.top());
        s.pop();
    }

    for (auto i : topo)
    {
        cout << i << " ";
    }
}

int main()
{
    vector<int> adj[11];
    int n = 11;

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 8, 9);

    find(adj, n);

    return 0;
}