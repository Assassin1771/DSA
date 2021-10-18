#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int a, int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
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

    cout << "PRINTING ADJACENCY LIST : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i << " : ";
        for (auto it : adj[i])
        {
            cout << it << " ";
        }

        cout << endl;
    }

    return 0;
}