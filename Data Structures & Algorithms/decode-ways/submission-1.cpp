class Solution {
    int solve(int i,string s,vector<int>&dp){
        int n=s.length();
        if(i<n&&s[i]=='0')return 0;
        if(i>=n-1)return 1;
        if(dp[i]!=-1)return dp[i];
        int alone=solve(i+1,s,dp);
        int with=0;
        int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if(num >= 10 && num <= 26)with = solve(i + 2, s, dp);
        return dp[i]=alone+with;
    }
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return solve(0,s,dp);
    }
};
