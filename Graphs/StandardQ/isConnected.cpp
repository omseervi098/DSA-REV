/*
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
*/
#include <bits/stdc++.h>
using namespace std;
// TIME --O(V+E)
void DFS(int **edges, int n, int stv, bool *visited)
{
    visited[stv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[stv][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited);
            visited[i] = true;
        }
    }
}
bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i <= n; i++)
        visited[i] = false;
    DFS(edges, n, 0, visited);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
            return false;
    }
    return true;
    // delete [] visited;
}
int main()
{
    int n, e;
    cin >> n >> e;
    int **out = new int *[n];
    for (int i = 0; i < n; i++)
    {
        out[i] = new int[n];
        for (int j = 0; j < n; j++)
            out[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        out[f][s] = 1;
        out[s][f] = 1;
    }
    bool ans = isConnected(out, n);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    for (int i = 0; i < n; i++)
        delete[] out[i];
    delete[] out;
}