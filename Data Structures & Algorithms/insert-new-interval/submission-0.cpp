class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int st=newInterval[0];
        int en=newInterval[1];
        int i=0;
        while(i<n&&intervals[i][1]<st){
            ans.push_back(intervals[i++]);
        }
        while(i<n&&intervals[i][0]<=en){
            st=min(st,intervals[i][0]);
            en =max(en,intervals[i][1]);
            i++;
        }
        vector<int>temp={st,en};
        ans.push_back(temp);
        while(i<n){
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};
