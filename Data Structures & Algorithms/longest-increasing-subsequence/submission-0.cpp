class Solution {
    int solve(int i,vector<vector<int>>&dp,vector<int>&nums,int j){
        if(i==nums.size())return 0;
        if(dp[i][j+1]!=-1)return dp[i][j+1];
        int notTake=solve(i+1,dp,nums,j);
        int take=0;
        if(j==-1||(j!=-1&&nums[j]<nums[i]))take=1+solve(i+1,dp,nums,i);
        return dp[i][j+1]=max(notTake,take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,dp,nums,-1);
    }
};
