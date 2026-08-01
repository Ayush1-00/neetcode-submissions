class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,float>>des;
        int len=speed.size();
        for(int i=0;i<len;i++){
            int dis=target-position[i];
            float time=float(dis)/(speed[i]);
            des.push_back({dis,time});
        }
        sort(des.begin(),des.end());
        stack<float>st;
        for(int i=0;i<len;i++){
            auto ele=des[i];
            if(st.empty())st.push(ele.second);
            else if(st.top()<ele.second)st.push(ele.second);
        }
        return st.size();
    }
};
