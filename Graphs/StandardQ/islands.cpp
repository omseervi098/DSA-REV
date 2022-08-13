/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
*/
//Time O(V+E)
#include <bits/stdc++.h>
using namespace std;
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
int islands(int **edges,int n){
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i])
        {
           DFS(edges, n, i, visited);
           ans++;
        }
    }
    return ans;
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
    int  ans =islands(out, n);
    cout<<ans<<endl;
    for (int i = 0; i < n; i++)
        delete[] out[i];
    delete[] out;
}