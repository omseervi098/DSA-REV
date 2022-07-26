//leetode problem no 378 
/*
Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13

Example 2:

Input: matrix = [[-5]], k = 1
Output: -5

*/

//one approach can be take vector and insert all element in that vector and sort it and return k th element
//this will take o(n^2)
//another is using binary search take o(nlog(max-min)) time and o(1) space
class Solution {
public:
    int lessthanequal(vector<vector<int>>& matrix,int target){
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
        int cnt=0;
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (target >= cur) {
                row++;
                cnt+=col+1;
            }
            else col--;
        }
        
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int min=matrix[0][0],max=matrix[n-1][n-1];
        while(min!=max){
            int mid=min+(max-min)/2;
            int cnt=lessthanequal(matrix,mid);
            if(cnt<k){
                min=mid+1;
            }else
                max=mid;
        }
        return min;
    }
};
