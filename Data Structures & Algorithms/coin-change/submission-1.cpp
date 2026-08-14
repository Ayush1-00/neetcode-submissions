class Solution {
    int solve(int i,int left,vector<vector<int>>&dp,vector<int>&coins){
        if(left==0)return 0;
        if(i<0)return 1e8;
        if(dp[i][left]!=-1)return dp[i][left];
        int notTake=solve(i-1,left,dp,coins);
        int take=1e8;
        if(left>=coins[i])take=1+solve(i,left-coins[i],dp,coins);
        return dp[i][left]=min(notTake,take);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return (solve(n-1,amount,dp,coins)>=1e8)?-1:solve(n-1,amount,dp,coins);
    }
};
