class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1)return nums[0];
        int len=nums.size();
        if(nums[0]<nums[len-1])return nums[0];
        int st=0;
        int en=len-1;
        while(st<en){
            int mid=st+(en-st)/2;
            if(nums[mid]>nums[en])st=mid+1;
            else en=mid;
        }
        return nums[en];
    }
};
