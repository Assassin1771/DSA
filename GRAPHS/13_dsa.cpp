#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    // Insert edge from u to v
    adj[u].push_back(v);
}

void dfs(vector<int> adj[], vector<int> &vis, int s, int count, stack<pair<int, int>> &st)
{
    vis[s] = 1;

    for (auto it : adj[s])
    {
        if (vis[it] == 0)
        {
            dfs(adj, vis, it, count + 1, st);
        }
    }

    st.push({s, count});
    return;
}

void find(vector<int> adj[], int v)
{
    vector<int> vis(v, 0);
    stack<pair<int, int>> st;

    for (int i = 1; i < v; i++)
    {
        if (vis[i] == 0)
        {
            dfs(adj, vis, i, 1, st);
        }
    }

    set<pair<int, int>> ss;

    while (st.empty() == false)
    {
        ss.insert({st.top()});
        st.pop();
    }

    for (auto it : ss)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    int n, m;
    n = 11;
    m = 13;

    vector<int> adj[n];

    // Given Directed Edges of graph
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 8);
    addEdge(adj, 2, 9);
    addEdge(adj, 3, 6);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 8);
    addEdge(adj, 5, 8);
    addEdge(adj, 6, 7);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 10);

    find(adj, n);

    return 0;
}