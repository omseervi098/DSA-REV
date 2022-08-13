/*
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
*/
#include <bits/stdc++.h>
using namespace std;
void DFS(int **edges, int n, int stv, bool *visited,vector<int> &comp)
{
    visited[stv] = true;
    comp.push_back(stv);
    for (int i = 0; i < n; i++)
    {
        if (edges[stv][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited,comp);
            visited[i] = true;
        }
    }
}
void allConnectedComponent(int **edges, int n)
{
    bool * visited=new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
           vector<int> v;
           DFS(edges, n, i, visited,v);
           sort(v.begin(),v.end());
           for(auto it:v)
               cout<<it<<" ";
           cout<<endl;
        }
    }
    delete [] visited;
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
    allConnectedComponent(out, n);
    for (int i = 0; i < n; i++)
        delete[] out[i];
    delete[] out;
}