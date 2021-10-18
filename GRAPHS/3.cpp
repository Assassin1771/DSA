//DFS TRAVERSAL

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs2(vector<int> adj[], vector<int> &vis, int s)
{
    vis[s] = 1;
    cout << s << " ";

    for (auto it : adj[s])
    {
        if (vis[it] == 0)
        {
            vis[it] = 1;
            dfs2(adj, vis, it);
        }
    }
}

void dfs(vector<int> adj[], int v)
{
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            dfs2(adj, vis, i);
        }
    }
}

int main()
{
    vector<int> adj[11];
    int n = 11;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 8, 9);

    cout << "DFS TRAVERSAL : " << endl;

    dfs(adj, n);

    return 0;
}