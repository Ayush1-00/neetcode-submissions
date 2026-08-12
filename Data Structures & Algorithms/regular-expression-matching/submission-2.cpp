class Solution {
    bool solve(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(j==s2.length())return i==s1.length();
        if(dp[i][j]!=-1)return dp[i][j];
        bool match = i<s1.length()&&(s1[i]==s2[j]||s2[j]=='.');
        if(j+1<s2.length()&&s2[j+1]=='*')return dp[i][j]=solve(i,j+2,s1,s2,dp)||(match&&solve(i+1,j,s1,s2,dp));
        if(match)return dp[i][j]=solve(i+1,j+1,s1,s2,dp);
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int l1=s.length();
        int l2=p.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,-1));
        return solve(0,0,s,p,dp);
    }
};
