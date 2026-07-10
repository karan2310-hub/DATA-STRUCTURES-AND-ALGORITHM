class Solution {
public:
void bfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int i,int j){
  
}
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int no_island=0;
        int cols=grid[0].size();
        // queue<pair<int,int>>q;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++  ){
            for(int j=0;j<cols;j++){
                if(visited[i][j]=false){
                    no_island++;
                   bfs(grid,visited,i,j);
                }
            }
        }
        return no_island;
    }
};
