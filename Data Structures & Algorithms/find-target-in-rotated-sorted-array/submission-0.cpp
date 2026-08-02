class Solution {
    int search (vector<int>arr,int s,int e,int target){
        while(s<=e){
            int mid=s+(e-s)/2;
            if(arr[mid]==target)return mid;
            else if(arr[mid]>target)e=mid-1;
            else s=mid+1;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if (len==1)return nums[0]==target?0:-1;
        if(nums[0]<nums[len-1])return search(nums,0,len-1,target);
        int s=0;
        int e=len-1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(nums[mid]>nums[e])s=mid+1;
            else e=mid;
        }
        if(target>nums[len-1])return search(nums,0,e-1,target);
        else return search(nums,e,len-1,target);
    }
};
