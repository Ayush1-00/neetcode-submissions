class Solution {
    int solve(int i,int left,vector<vector<int>>&dp,vector<int>&coins){
        if (left == 0)
            return 0;

        if (i == coins.size())
            return 1e8;

        if (dp[i][left] != -1)
            return dp[i][left];

        // Don't take current coin
        int notTake = solve(i + 1, left, dp, coins);

        // Take current coin
        int take = 1e8;

        if (coins[i] <= left)
            take = 1 + solve(i, left - coins[i], dp, coins);

        return dp[i][left] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,dp,coins)<1e8?solve(0,amount,dp,coins):-1;
    }
};
