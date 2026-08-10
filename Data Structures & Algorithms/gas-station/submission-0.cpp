class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0;
        int curr=0;
        int ind=0;
        for(int i=0;i<cost.size();i++){
            int diff=gas[i]-cost[i];
            total+=diff;
            curr+=diff;
            if(curr<0){
                curr=0;
                ind=i+1;
            }
        }
        return total>=0?ind:-1;
    }
};
