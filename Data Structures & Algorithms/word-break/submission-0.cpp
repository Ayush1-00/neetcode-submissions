class Solution {
    bool solve(int i,vector<int>&dp,string s,unordered_map<string,bool>&m){
        if(i==s.length())return true;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        for(int j=i;j<s.length();j++){
            temp+=s[j];
            if(m[temp]&&solve(j+1,dp,s,m))return dp[i]=true;
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<int>dp(n,-1);
        unordered_map<string,bool>m;
        for(string x:wordDict){
            m[x]=true;
        }
        return solve(0,dp,s,m);
    }
};
