class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>m;
        if(hand.size()%groupSize!=0)return false;
        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            int ele=hand[i];
            if(m[ele]>0){
                for(int j=0;j<groupSize;j++){
                    if(m[ele+j]<=0)return false;
                    m[ele+j]--;
                }
            }
        }
        return true;
    }
};
