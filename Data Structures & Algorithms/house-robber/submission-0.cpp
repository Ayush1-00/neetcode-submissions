class Solution {
    int solve(int n,vector<int>& nums,vector<int>&dp){
        if(n==1)return dp[n-1]=nums[n-1];
        if(n==2)return dp[n-1]=max(nums[n-1],nums[n-2]);
        if(dp[n-1]!=-1)return dp[n-1];
        int maxi=max(solve(n-2,nums,dp)+nums[n-1],solve(n-1,nums,dp));
        return dp[n-1]=maxi;
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n,nums,dp);
    }
};
