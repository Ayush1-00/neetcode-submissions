class Solution {
    bool solve(int i,vector<int>&nums,vector<vector<int>>&dp,int left){
        if(left==0)return true;
        if(i==nums.size())return false;
        if(dp[i][left]!=-1)return dp[i][left];
        bool notTake=solve(i+1,nums,dp,left);
        bool take=false;
        if(left>=nums[i])take=solve(i+1,nums,dp,left-nums[i]);
        return dp[i][left]=notTake||take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum%2!=0)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(0,nums,dp,target);
    }
};
