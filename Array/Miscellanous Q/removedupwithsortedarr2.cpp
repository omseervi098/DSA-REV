//leetcode problem no 80

//one way is we can take another array
// take unordered map to store freq of each element
//according we can fille new array andr return it
//that will take o(n)time and o(n) space
//but can we do this in-place ?

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        int j=0;
        for(int i=1;i<arr.size();){
            if(arr[i]==arr[i-1]){
                cnt++;
                if(cnt==2){
                    j++;
                    arr[j]=arr[i];
                }
                i++;
            }else{
                arr[j+1]=arr[i];
                cnt=1;j++;
                i++;
            }
        }
        return j+1;
    }
};