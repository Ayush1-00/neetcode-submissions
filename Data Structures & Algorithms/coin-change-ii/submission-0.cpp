class Solution {
    int solve(int i,int left,vector<vector<int>>&dp,vector<int>&coins){
        if(left==0)return 1;
        if(i<0||left<0)return 0;
        if(i==0)return dp[i][left]=(left%coins[i]==0?1:0);
        if(dp[i][left]!=-1)return dp[i][left];
        int take=solve(i,left-coins[i],dp,coins);
        int notTake=solve(i-1,left,dp,coins);
        return dp[i][left]=take+notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,dp,coins);
    }
};
