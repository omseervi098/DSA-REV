/*
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/
//Leetcode problem no 74
// good observed approach -- o(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //o(R+C)
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
	    // look matrix from top right it will look like bst
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //o(R*log(C))
        for(int i=0;i<matrix.size();i++){
            if(i<matrix.size() and matrix[i][0]>target){
                break;
            }else{
            int st=0,end=matrix[0].size()-1;
            while(st<=end){
                int mid=(st+end)/2.0;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]>target){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }}
        }
        return false;
}
// MORE BETTER is to search valid row also using binary search
class Solution {
public:
    //o(logm +logn) --> o(log(mn))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=0,rowe=matrix.size()-1;
        int ans=0;
        while(rows<=rowe){
            int mid=(rows+rowe)/2;
            if(matrix[mid][0]<=target and target<=matrix[mid][matrix[mid].size()-1]){
                ans=mid;
                break;
            }
            else if(matrix[mid][0]>target){
                rowe=mid-1;
            }else{
                rows=mid+1;
            }
        }
         
            int st=0,end=matrix[0].size()-1;
            while(st<=end){
                int mid=(st+end)/2.0;
                if(matrix[ans][mid]==target)
                    return true;
                else if(matrix[ans][mid]>target){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }
        
        return false;
    }
};