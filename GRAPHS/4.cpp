// CYCLE DETECTION USING BFS

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool check1(vector<int> adj[], vector<int> &vis, int v, int s)
{
    vis[s] = 1;

    queue<pair<int, int>> q;
    q.push({s, -1});

    while (!q.empty())
    {
        int curr = q.front().first;
        int prev = q.front().second;

        q.pop();

        for (auto it : adj[curr])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push({it, curr});
            }

            else if (it != prev)
                return true;
        }
    }

    return false;
}

void check(vector<int> adj[], int v)
{
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++)
    {
        if (vis[i] == 0)
        {
            if (check1(adj, vis, v, i))
            {
                cout << "CYCLE EXISTS";
                return;
            }
        }
    }

    cout << "CYCLE DOESN'T EXISTS";
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

    check(adj, n);

    return 0;
}