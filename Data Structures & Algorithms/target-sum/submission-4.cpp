class Solution {
    int solve(int i,int left,vector<vector<int>>&dp,vector<int>&nums,int sum){
        if(abs(left)>sum)return 0;
        if(i == 0)return abs(left) == nums[i] ? (nums[i] == 0 ? 2 : 1) : 0;
        if(dp[i][left+sum]!=-1)return dp[i][left+sum];
        return dp[i][left+sum]=solve(i-1,left-nums[i],dp,nums,sum)+solve(i-1,left+nums[i],dp,nums,sum);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int ele:nums){
            sum+=ele;
        }
        if(abs(target) > sum)return 0;
        int n=nums.size();
        int n1=2*sum+1;
        vector<vector<int>>dp(n,vector<int>(n1,-1));
        return solve(n-1,target,dp,nums,sum);
    }
};

