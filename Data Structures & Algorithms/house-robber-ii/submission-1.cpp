class Solution {
    int solve(int i,vector<int>&nums,vector<int>&dp,int n){
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]=max(nums[i]+solve(i+2,nums,dp,n),solve(i+1,nums,dp,n));
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        vector<int>dp1(n,-1);
        return max(solve(0,nums,dp,n-2),solve(1,nums,dp1,n-1));
    }
};
