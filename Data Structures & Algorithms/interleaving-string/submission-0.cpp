class Solution {
    bool solve(int i,int j,int k,string s1,string s2,string s3,vector<vector<int>>&dp){
        if(k==s3.length())return i==s1.length()&&j==s2.length();
        if(dp[i][j]!=-1)return dp[i][j];
        if(i<s1.length()&&s1[i]==s3[k]){
            if(solve(i+1,j,k+1,s1,s2,s3,dp))return dp[i][j]=true;
        }
        if(j<s2.length()&&s2[j]==s3[k]){
            if(solve(i,j+1,k+1,s1,s2,s3,dp))return dp[i][j]=true;
        }
        return dp[i][j]=false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
        if(n1+n2!=n3)return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};
