class Solution {
    bool solve(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()-1)return true;
        if(nums[i]==0)return false;
        if(dp[i]!=-1)return dp[i];
        bool flag=false;
        int n=nums[i];
        for(int j=1;j<=n;j++){
            flag=solve(nums,i+j,dp)||flag;
        }
        return dp[i]=flag;
    }
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};
