class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>delay(n+1,1e8);
        delay[k]=0;
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[w,ni]=pq.top();
            pq.pop();
            if(delay[ni]<w)continue;
            for(auto[node,dis]:adj[ni]){
                if(dis+w<delay[node]){
                    delay[node]=dis+w;
                    pq.push({delay[node],node});
                }
            }
        }
        int mini=0;
        for(int i=1;i<n+1;i++){
            if(delay[i]==1e8)return -1;
            mini=max(mini,delay[i]);
        }
        return mini;
    }
};
