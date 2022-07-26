//leetcode problem no 240
//1 st approach take o(r*log(c)) time
class Solution {
public:
    bool binarysearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int st=0,end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(arr[mid]==k){
                return true;
            }else if(arr[mid]>k){
                end=mid-1;
            }else
               st=mid+1;
        }return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){

                bool ans=binarysearch(matrix[i],target);
                if(ans==true)return true;
            }
        return false;
    }
};

// now there is one more approach which take take o(r+c)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //o(R+C) far better
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
	    // look matrix from top right it will look like tree
        //u can also do same think from left bottom
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};