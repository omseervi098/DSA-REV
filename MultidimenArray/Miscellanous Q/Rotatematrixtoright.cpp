//link :https://www.codingninjas.com/codestudio/problems/rotate-matrix-by-k_840699
/*
You have been given a matrix ‘MAT’ of size 'N' * 'M' (where 'N' and 'M' denote the number of rows and columns respectively) and a positive integer ‘K’. Your task is to rotate the matrix to the right 'K' times.
Note:

Right rotation on a matrix is shifting each column to the right side (the last column moves to the first column) and 'K' times means performing this rotation 'K' times.

Example:

For 'K' = 1 and the given 'MAT':

1 2 3
4 5 6
7 8 9

Output after rotating 'MAT' one time is:

3 1 2 
6 4 5
9 7 8
*/
vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) {
    // solution take o(n*m*m) time
	k=k%m;
    for(int l=0;l<k;l++){
        for(int i=0;i<n;i++){
            int temp=mat[i][m-1];
            for(int j=m-1;j>=0;j--){
                
                mat[i][j]=mat[i][j-1];//left shifiting
            }
            mat[i][0]=temp;
        }
    }vector<int> v;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            v.push_back(mat[i][j]);
        }
    }return v;
}
//better approach
vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) {
	// o(n*m)
    int a = k%m;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        //v.push_back(mat[i][a]);
        for(int j=0;j<m;j++)
        {
            int c = ((m-a)+j)%m;
            v.push_back(mat[i][c]);
        }
    }
    return v;
}