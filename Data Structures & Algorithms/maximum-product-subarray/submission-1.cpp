class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin=nums[0];
        int currMax=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            int flag=currMax;
            currMax=max(nums[i],max(currMin*nums[i],currMax*nums[i]));
            currMin=min(nums[i],min(currMin*nums[i],flag*nums[i]));
            maxi=max(currMax,maxi);
        }
        return maxi;
    }
};
