class Solution {
    void solve(int i,unordered_map<int,bool>&m,vector<vector<int>>&adj){
        m[i]=true;
        for(int ele:adj[i]){
           if(!m[ele])solve(ele,m,adj);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,bool>m;
        int count=0;
        for(int i=0;i<n;i++){
            if(!m[i]){
                count++;
                solve(i,m,adj);
            }
        }
        return count;
    }
};
