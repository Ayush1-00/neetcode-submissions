class Solution {
    int solve(int i,vector<int>&prices,int j,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(i==prices.size()-1)return dp[i][j]=(j==1?prices[i]:0);
        if(dp[i][j]!=-1)return dp[i][j];
        if(j==0){
            return dp[i][j]=max(solve(i+1,prices,1,dp)-prices[i],solve(i+1,prices,0,dp));
        }
        else return dp[i][j]=max(solve(i+2,prices,0,dp)+prices[i],solve(i+1,prices,1,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,0,dp);
    }
};
