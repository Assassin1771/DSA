//TOPO SORT USING BFS

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
}

void find(vector<int> adj[], int v)
{
    vector<int> topo;
    vector<int> indegree(v, 0);

    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();

        topo.push_back(curr);

        for (auto it : adj[curr])
        {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    for (auto it : topo)
        cout << it << " ";
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