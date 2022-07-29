//Bruteforce DFS O(r*r*c)
class Solution {
public:
    int helper(vector<vector<int>> &mat,int x,int y,int m,int n,vector<vector<bool>> & visited){
        if(x<0||y<0 ||x>=m||y>=n||visited[x][y])
            return 100001;
        if(mat[x][y]==0)return 0;
        visited[x][y]=true;
        int val=1+min(min(helper(mat,x+1,y,m,n,visited),helper(mat,x-1,y,m,n,visited)),min(helper(mat,x,y+1,m,n,visited),helper(mat,x,y-1,m,n,visited)));
        visited[x][y]=false;
        return val;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       
        int m=mat.size(),n=mat[0].size();
         vector<vector<int>> result(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]>0){
                    vector<vector<bool>> visited(m,vector<bool>(n));
                    result[i][j]=helper(mat,i,j,m,n,visited);
                }
            }
        }
        return result;
    }
};
//Optimised BFS O(r*c) and space O(r*c)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({ i, j }); //Put all 0s in the queue.
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};
//Optimised space to O(1) using DP
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int maxVal=m+n; //As elements can only be 0 or 1.
        //to bottom and to right
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)continue;
                
                int top=maxVal;int left=maxVal;
                if(i>=1)top=mat[i-1][j];
                if(j>=1)left=mat[i][j-1];
                mat[i][j]=min(top,left)+1;
            }
        }
        //to top and left
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(mat[i][j]==0)continue;
                
                int bottom=maxVal;int right=maxVal;
                if(i<m-1)bottom=mat[i+1][j];
                if(j<n-1)right=mat[i][j+1];
                mat[i][j]=min(mat[i][j],min(bottom,right)+1);
            }
        }
        
        return mat;
    }
};