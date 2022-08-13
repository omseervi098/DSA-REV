/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
*/
// Gives TLE because it takeing time comparing every character and pushing
#include <bits/stdc++.h>
using namespace std;

bool helper(vector<vector<char>> &board, int n, int m, int i, int j, string str, vector<vector<bool>> &visited)
{
    if (i < 0 || j < 0 || i == n || j == m || visited[i][j] == true || str.size() > 10)
        return false;
    // cout<<i<<" "<<j<<endl;
    if (str == "CODINGNINJ" and board[i][j] == 'A')
    {
        return true;
    }
    visited[i][j] = true;
    if (i + 1 < n)
    {
        bool bottom = helper(board, n, m, i + 1, j, str + board[i][j], visited);
        if (bottom)
            return true;
    }
    if (i - 1 >= 0)
    {
        bool top = helper(board, n, m, i - 1, j, str + board[i][j], visited);
        if (top)
            return true;
    }
    if (j + 1 < m)
    {
        bool right = helper(board, n, m, i, j + 1, str + board[i][j], visited);
        if (right)
            return true;
    }
    if (j - 1 >= 0)
    {
        bool left = helper(board, n, m, i, j - 1, str + board[i][j], visited);
        if (left)
            return true;
    }
    if (i - 1 >= 0 and j - 1 >= 0)
    {
        bool topleft = helper(board, n, m, i - 1, j - 1, str + board[i][j], visited);
        if (topleft)
            return true;
    }
    if (i - 1 >= 0 and j + 1 < m)
    {
        bool topright = helper(board, n, m, i - 1, j + 1, str + board[i][j], visited);
        if (topright)
            return true;
    }
    if (i + 1 < n and j - 1 >= 0)
    {
        bool bottomleft = helper(board, n, m, i + 1, j - 1, str + board[i][j], visited);
        if (bottomleft)
            return true;
    }
    if (i + 1 < n and j + 1 < m)
    {
        bool bottomright = helper(board, n, m, i + 1, j + 1, str + board[i][j], visited);
        if (bottomright)
            return true;
    }
    visited[i][j] = false;
    return false;
}
bool hasPath(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {
                if (helper(board, n, m, i, j, "", visited))
                    return true;
            }
        }
    }
    return false;
}

// Optimised
bool dfs(vector<vector<char>> &board, int n, int m, int ci, int cj, vector<vector<bool>> &visited, string s)
{
    if (s.size() == 0)
    {
        return true;
    }
    visited[ci][cj] = true;

    bool ans = false;
    if (ci + 1 < n && !visited[ci + 1][cj] && board[ci + 1][cj] == s[0]) // down
    {
        if (dfs(board, n, m, ci + 1, cj, visited, s.substr(1)))
            return true;
    }

    if (ci - 1 >= 0 && !visited[ci - 1][cj] && board[ci - 1][cj] == s[0]) // up

    {
        if (dfs(board, n, m, ci - 1, cj, visited, s.substr(1)))
            return true;
    }
    if (cj - 1 >= 0 && !visited[ci][cj - 1] && board[ci][cj - 1] == s[0]) // left
    {
        if (dfs(board, n, m, ci, cj - 1, visited, s.substr(1)))
            return true;
    }

    if (cj + 1 < m && !visited[ci][cj + 1] && board[ci][cj + 1] == s[0]) // right
    {
        if (dfs(board, n, m, ci, cj + 1, visited, s.substr(1)))
            return true;
    }

    if (ci + 1 < n && cj - 1 >= 0 && !visited[ci + 1][cj - 1] && board[ci + 1][cj - 1] == s[0]) // down left
    {
        if (dfs(board, n, m, ci + 1, cj - 1, visited, s.substr(1)))
            return true;
    }

    if (ci + 1 < n && cj + 1 < m && !visited[ci + 1][cj + 1] && board[ci + 1][cj + 1] == s[0]) // down right
    {
        if (dfs(board, n, m, ci + 1, cj + 1, visited, s.substr(1)))
            return true;
    }

    if (ci - 1 >= 0 && cj - 1 >= 0 && !visited[ci - 1][cj - 1] && board[ci - 1][cj - 1] == s[0]) // up left
    {
        if (dfs(board, n, m, ci - 1, cj - 1, visited, s.substr(1)))
            return true;
    }

    if (ci - 1 >= 0 && cj + 1 < m && !visited[ci - 1][cj + 1] && board[ci - 1][cj + 1] == s[0]) // up right
    {
        if (dfs(board, n, m, ci - 1, cj + 1, visited, s.substr(1)))
            return true;
    }

    visited[ci][cj] = false;

    return ans;
}
bool hasPath(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'C')
            {

                string s = "ODINGNINJA";

                if (dfs(board, n, m, i, j, visited, s))
                    return true;
            }
        }
    }
    return false;
}

// Another Approach
// Dir ==  all 8 direction
// Time Complexity O(N*M)
int dXdY[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
bool dfs(vector<vector<char>> &board, int n, int m, int i, int j, vector<vector<bool>> &visited, string s, int idx)
{
    if(idx==11) return true;
    visited[i][j]=true;
    bool found=false;
    for(int k=0;k<8;k++){
        int newX=i+dXdY[k][0];
        int newY=j+dXdY[k][1];
        if(newX<0 || newY<0 || newX==n ||newY==m) {
            continue;
        }
        if(board[newX][newY]==s[idx] and !visited[newX][newY]){
            found=found | dfs(board,n,m,newX,newY,visited,s,idx+1);
        }
    }
    visited[i][j]=false;
    return found;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string s = "CODINGNINJA";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == s[0])
                if (dfs(board, n, m, i, j, visited, s, 1))
                    return true;
        }
    }
    return false;
}
