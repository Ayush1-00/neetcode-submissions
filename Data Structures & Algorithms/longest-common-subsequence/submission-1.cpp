class Solution {
    int solve(int i,int j,vector<vector<int>>&dp,string s1,string s2){
        if(i<0||j<0)return 0;
        if(i==0&&j==0)return dp[i][j]=(s1[0]==s2[0]?1:0);
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=1+solve(i-1,j-1,dp,s1,s2);
        return dp[i][j]=max(solve(i-1,j,dp,s1,s2),solve(i,j-1,dp,s1,s2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return solve(n-1,m-1,dp,text1,text2);
        if(text1[0]==text2[0])dp[1][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
