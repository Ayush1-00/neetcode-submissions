class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            if(nums[num]<0)return num;
            nums[num]=-nums[num];
        }
        return -1;
    }
};
