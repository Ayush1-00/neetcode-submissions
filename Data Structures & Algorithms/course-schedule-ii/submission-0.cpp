class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>ans;
        vector<int>indegree(n,0);
        queue<int>q;
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][1];
            int v=pre[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            count++;
            ans.push_back(ele);
            for(int x:adj[ele]){
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        vector<int>temp={};
        return count==n?ans:temp;
    }
};
