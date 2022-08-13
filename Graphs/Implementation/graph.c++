#include<bits/stdc++.h>
using namespace std;
void printdfs(vector<vector<int>> &graph,int n,int st,unordered_map<int,bool> &visited){
    cout<<st<<" ";
    visited[st]=true;
    for(int i=0;i<n;i++){
        if(graph[st][i]==1 and visited.count(i)==0){
            printdfs(graph,n,i,visited);
        }
    }
}
//For Disconnected Graph apply traversal for every component
void printbfs(vector<vector<int>> &graph,int n,int st){
    queue<int> q;
    unordered_map<int,bool> visited;
    q.push(st);
    visited[st]=true;
    while(!q.empty()){
        int front=q.front();q.pop();
        cout<<front<<" ";
        for(int i=0;i<n;i++){
            if(graph[front][i]==1 and visited.count(i)==0){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
bool hasPath(vector<vector<int>> &graph,int n,int st,int end,unordered_map<int,bool> &visited){
    if(st==end)
       return true;
    
    visited[st]=true;
    for(int i=0;i<n;i++){
        if(graph[st][i]==1 and visited.count(i)==0){
            bool subans=hasPath(graph,n,i,end,visited);
            if(subans) return true;
        }
    }
    return false;
}
bool getPathDFS(vector<vector<int>> &graph,int n,int st,int end,unordered_map<int,bool> &visited,vector<int> &path){
    if(st==end){
        path.push_back(st);
       return true;
    }
    path.push_back(st);
    visited[st]=true;
    for(int i=0;i<n;i++){
        if(graph[st][i]==1 and visited.count(i)==0){
            if(getPathDFS(graph,n,i,end,visited,path))
             return true;
        }
    }
    path.pop_back();
    return false;
}
void getPathBFS(vector<vector<int>> &graph,int n,int st,int end,unordered_map<int,bool> &visited,vector<int> &path){
    queue<int> q;
    visited[st]=true;
    unordered_map<int,int> m;
    q.push(st);
    while (!q.empty())
    {
        int front=q.front();q.pop();
        if(front==end){
            path.push_back(front);
            while(m.count(front)>0){
                path.push_back(m[front]);
                front=m[front];
            }
            return;
        }
        for(int i=0;i<n;i++){
            if(graph[front][i]==1 and visited.count(i)==0){
                m[i]=front;
                q.push(i);
                visited[i]=true;
            }
        }
    }
}
int main(){
    int n,e;cin>>n>>e;
    vector<vector<int>> graph(n,vector<int>(n,0));
    unordered_map<int,bool> visited;
    for(int i=0;i<e;i++){
        int first,second;
        cin>>first>>second;
        graph[first][second]=1;
        graph[second][first]=1;
    }
    cout<<"BFS:";
    printbfs(graph,n,0);
    cout<<endl;
    int st,end;
    cin>>st>>end;
    vector<int> path;
    getPathBFS(graph,n,st,end,visited,path);
    for(auto it:path){
        cout<<it<<" ";
    }
    cout<<endl;
}