//BFS o(r*c)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int time=0;
        vector<pair<int,int>> v{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty() and fresh>0){
            cout<<fresh<<endl;
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(auto it:v){
                    int r=row+it.first;
                    int c=col+it.second;
                    if(r<0||c<0||r==m||c==n||grid[r][c]!=1)
                        continue;
                    grid[r][c]=2;
                    q.push({r,c});
                    fresh--;
                }
            }
            time++;
        }
        if(fresh) return -1;
        return time;
    }
};