//CHECK BIPARTITE USING DFS

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}

bool check1(vector<int> adj[], vector<int> &color, int s)
{
    color[s] = 1;

    for (auto it : adj[s])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[s];
            check1(adj, color, it);
        }

        else if (color[it] == color[s])
            return false;
    }

    return true;
}

void check(vector<int> adj[], int v)
{
    vector<int> color(v, -1);

    for (int i = 0; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (check1(adj, color, i))
            {
                cout << "IT IS A BIPARTITE" << endl;
                return;
            }
        }
    }

    cout << "NOT A BIPARTITE";
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