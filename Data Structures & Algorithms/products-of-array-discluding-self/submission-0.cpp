class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int>left(len);
        left[0]=nums[0];
        vector<int>right(len);
        right[len-1]=nums[len-1];
        for(int i=1;i<len;i++){
            left[i]=left[i-1]*nums[i];
            right[len-1-i]=right[len-i]*nums[len-i-1];
        }
        vector<int>ans(len);
        ans[0]=right[1];
        ans[len-1]=left[len-2];
        for(int i=1;i<len-1;i++){
            ans[i]=left[i-1]*right[i+1];
        }
        return ans;
    }
};
