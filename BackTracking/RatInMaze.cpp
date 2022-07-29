/*
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1

Sample Output 1 :
1 0 0 1 0 0 1 1 1 

Explanation :
Only 1 path is possible. The path is shown in the image below.
*/
/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
//tIME O(2^K) K is no of cell with value 1
#include<bits/stdc++.h>
using namespace std;
void solveMazeUtil(int maze[][20],int x, int y, int sol[][20],int N);
void printSolution(int sol[][20],int N)//
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            printf("%d ",sol[i][j]);
    }
    printf("\n");
}
bool isSafe(int maze[][20], int x, int y,int N)
{
     if(x>=N || x<0 || y>=N || y<0 || maze[x][y] ==0){
         return false;
      }
    return true;
}
void solveMaze(int maze[][20],int N)
{
    int sol[20][20];
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            sol[i][j] = 0;
        }
    }
    solveMazeUtil(maze, 0, 0, sol,N);
    return;
}
void solveMazeUtil(int maze[][20],int x, int y, int sol[][20],int N)
{    
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) 
    {
        sol[x][y] =1;
        printSolution(sol,N);
        sol[x][y]=0;
        return;
    }
    if (isSafe(maze, x, y,N) == true) 
    {   
          if (sol[x][y] == 1)
              return;
        sol[x][y] = 1;
        /* Move forward in x direction */
        solveMazeUtil(maze, x - 1, y, sol,N);
        
        solveMazeUtil(maze, x + 1, y, sol,N);
        
        solveMazeUtil(maze, x, y - 1, sol,N);
         
        solveMazeUtil(maze, x, y + 1, sol,N);
       
        sol[x][y] = 0;
    }
    return;
}

int main() 
{
	// Write your code here   
    
    int N;
    cin >> N;
    
    int a[20][20];
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> a[i][j];
        }
    }
    
    solveMaze(a,N);
	return 0;
};




