class Solution {
public:

  int curr=0;// ye dono area liye h
  int ans=0;
  void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col){
    int rows=grid.size();
    int cols=grid[0].size();
    // curr++;
    // ans=max(ans,curr);
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
        auto i=q.front();
        q.pop();
        int r=i.first;
        int c=i.second;
        //abhi ka idx mil gya


       // /aab neighbours liye
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        for(int k=0; k<4; k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 and nr<rows and nc>=0 and nc<cols and !visited[nr][nc] and grid[nr][nc]==1){
                 curr++;
    ans=max(ans,curr);
                visited[nr][nc]=true;
                q.push({nr,nc});
            }
        }
    }
    return;

  }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<bool>>visited(r,vector<bool>(c,false));
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]==1 and !visited[i][j]){
                   curr=1;
                    visited[i][j]=true;
                    bfs(grid,visited,i,j);
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};
