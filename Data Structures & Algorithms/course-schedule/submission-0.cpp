class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            count++;
            for(int x:adj[ele]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        return count==n;
    }
};
