class Solution {
public:
int dr[4]={-1,1,0,0};
int dc[4]={0,0,-1,1};
vector<vector<bool>>safe;
vector<vector<bool>>visited;
void dfs(vector<vector<char>>& board,int row, int col){


    
    for(int k=0; k<4 ; k++){
        //charo neighbours
        int r=row+dr[k];
        int c=col+dc[k];
        if(r>=0 and r<board.size()
        and c>=0 and c<board[0].size()
        and !visited[r][c])
        {if(board[r][c]=='O'){
            safe[r][c]=true;
            visited[r][c]=true;
            dfs(board,r,c);
        }}
    }

    return;
}
    void solve(vector<vector<char>>& board) {
      safe.resize(board.size(),vector<bool>(board[0].size(),false));
      visited.resize(board.size(),vector<bool>(board[0].size(),false));
        int m=board.size()-1;
        int n=board[0].size()-1;
        for(int i=0;i<=m; i++){
            //abhi safe mark nhi kr rhe, as ye sv to border wle 0 hai , safe hi hoge, and o to xsmy border wale pe traverse krege hi nhi simple
            if(board[i][0]=='O' and !visited[i][0]){
                visited[i][0]=true;
                
                dfs(board,i,0);
            }
            if(board[i][n]=='O' and !visited[i][n]){
                visited[i][n]=true;
                dfs(board,i,n);
            }

        }
        for(int i=0;i<=n; i++){
            if(board[0][i]=='O' and !visited[0][i]){
                visited[0][i]=true;
                dfs(board,0,i);
            }
            if(board[m][i]=='O' and !visited[m][i]){
                visited[m][i]=true;
                dfs(board,m,i);
            }

        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n ;j++){
                if(board[i][j]=='O' and !safe[i][j]) board[i][j]='X';
            }
        }
        return;
    }
};
// jitne v O wale hain, unme se jo v edge pe hai unko chorke, svko x kr do.....

/*isme bhi ek catch like pacific atlantic:
            ->yha kisi se connected svpe jayege ad dekhege ki border tk to nhi ja rhe,
            =>better, ki border wale O se svpe jake dekh len.*/
