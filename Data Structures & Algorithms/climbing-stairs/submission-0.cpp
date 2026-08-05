class Solution {
    int solve(int i,vector<int>&dp){
        if(i==1||i==2)return dp[i-1]=i;
        if(dp[i-1]!=-1)return dp[i-1];
        int ways=solve(i-1,dp)+solve(i-2,dp);
        return dp[i-1]=ways;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n,-1);
        return solve(n,dp);
        
    }
};
