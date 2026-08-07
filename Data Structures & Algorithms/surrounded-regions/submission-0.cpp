class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>flag(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                flag[0][i]=true;
                q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                flag[n-1][i]=true;
                q.push({n-1,i});
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                flag[i][0]=true;
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                flag[i][m-1]=true;
                q.push({i,m-1});
            }
        }
        vector<int> row={0,0,-1,1};
        vector<int> col={-1,1,0,0};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ri=r+row[i];
                int cj=c+col[i];
            
                if(ri>=0&&ri<n&&cj>=0&&cj<m&&board[ri][cj]=='O'&&flag[ri][cj]==false){
                    flag[ri][cj]=true;
                    q.push({ri,cj});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&flag[i][j]==false)board[i][j]='X';
            }
        }
    }
};
