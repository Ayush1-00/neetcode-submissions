class DJS{
    vector<int>rank;
    vector<int>parent;
    public:
    DJS(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    
    int find(int ele){
        if(parent[ele]==ele)return ele;
        return parent[ele]=find(parent[ele]);
    }
    bool join(int u,int v){
        int p1=find(u);
        int p2=find(v);
        if(p1==p2)return false;
        else if(rank[p1]>rank[p2])parent[p2]=p1;
        else if(rank[p1]<rank[p2])parent[p1]=p2;
        else {
            parent[p2]=p1;
            rank[p1]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DJS djs(n);
        vector<int>ans(2);
        for(int i=0;i<n;i++){
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;
            if(!djs.join(u,v))ans={u+1,v+1};
        }
        return ans;
    }
};
