class Solution {
    int solve(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i==0&&j==0)return dp[i][j]=(s[i]==t[j]?1:0);
        if(i<0)return 0;
        if(j<0)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if(s[i]==t[j])take=solve(i-1,j-1,s,t,dp);
        int notTake=solve(i-1,j,s,t,dp);
        return dp[i][j]=take+notTake;
    }
public:
    int numDistinct(string s, string t) {
        int l1=s.length();
        int l2=t.length();
        if(l1<l2)return 0;
        vector<vector<int>>dp(l1,vector<int>(l2,-1));
        return solve(l1-1,l2-1,s,t,dp);
    }
};
