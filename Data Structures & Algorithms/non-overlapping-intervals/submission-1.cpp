class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int pre=INT_MIN;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=pre)pre=intervals[i][1];
            else {
                pre=min(pre,intervals[i][1]);
                count++;
            }
        }
        return count;
    }
};
