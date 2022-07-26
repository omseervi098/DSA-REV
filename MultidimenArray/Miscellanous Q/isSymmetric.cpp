// problem link:  https://www.codingninjas.com/codestudio/problems/matrix-is-symmetric_799361?leftPanelTab=1
/*
Sample Input 1 :

1
3
1 2 3 2 4 5 3 5 8

Sample Output 1 :

Yes

*/
// one approach can be make another matrix which is transpose of given matrix then we can check whether they are same matrix
//time o(n^2) space O(n^2)
//another approach is check equality 
//time o(n^2) space o(1)
bool isMatrixSymmetric(vector<vector<int>> matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<i;j++){
            if(matrix[i][j]!=matrix[j][i])return false;
        }
    }return true;
}