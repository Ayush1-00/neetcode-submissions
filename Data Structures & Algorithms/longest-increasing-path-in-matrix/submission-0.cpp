class Solution {
    vector<int>rows={0,0,-1,1};
    vector<int>cols={-1,1,0,0};
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&matrix,int val){
        int n=matrix.size();
        int m=matrix[0].size();
        if(i<0||i>=n||j<0||j>=m||matrix[i][j]<=val)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=1;
        for(int k=0;k<4;k++){
            maxi=max(maxi,1+solve(i+rows[k],j+cols[k],dp,matrix,matrix[i][j]));
        }
        return dp[i][j]=maxi;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxLen=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxLen=max(maxLen,solve(i,j,dp,matrix,INT_MIN));
            }
        }
        return maxLen;
    }
};
