/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        auto cmp=[](Interval a,Interval b){
            return a.start<b.start;
        };
        sort(intervals.begin(),intervals.end(),cmp);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<intervals.size();i++){
            if(!pq.empty()&&pq.top()<=intervals[i].start)pq.pop();
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};
