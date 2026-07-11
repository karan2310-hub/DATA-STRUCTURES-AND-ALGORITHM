class Solution {
public:
void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
 int rows=grid.size();
 int cols=grid[0].size();
 queue<pair<int,int>>q;
 q.push({row,col});
 while(!q.empty()){
    auto curr=q.front();//for neighbours
    q.pop();
    int r=curr.first;
    int c=curr.second;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};
    for(int i=0; i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        //pehla neigh mila nr nc
        if(nr>=0 and nr<rows and nc>=0 and nc<cols
        and visited[nr][nc]!=true and grid[nr][nc]=='1'){
            visited[nr][nc]=true;
            bfs(grid,visited,nr,nc);
        }
    }

 }
 return;

}
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int no_of_island=0;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));      
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1' and visited[i][j]!=true){
                    no_of_island++;
                    bfs(grid,visited,i,j);
                }
            }
        }
        return no_of_island;
    }
};