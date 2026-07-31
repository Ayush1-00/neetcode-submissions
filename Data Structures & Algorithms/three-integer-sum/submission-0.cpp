class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size()-2){
            vector<int>temp(3);
            int left=0-nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]==left){
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    ans.insert(temp);
                    j++;
                    k--;
                }
                else if(nums[j]+nums[k]>left)k--;
                else j++;
            }
            i++;
        }
        vector<vector<int>>ans1;
        for(auto ele:ans){
            ans1.push_back(ele);
        }
        return ans1;
    }
};
