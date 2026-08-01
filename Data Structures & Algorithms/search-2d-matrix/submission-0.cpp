class Solution {
    bool search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size()-1;
        for(int i=0;i<matrix.size();i++){
            if(target>=matrix[i][0]&&target<=matrix[i][n])return search(matrix[i],target);
        }
        return false;
    }
};
