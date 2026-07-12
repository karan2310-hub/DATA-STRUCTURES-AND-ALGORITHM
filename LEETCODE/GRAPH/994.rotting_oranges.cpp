class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int,int>> q;

        int fresh = 0;

        // Initial traversal
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if(grid[i][j] == 2)//pehle rot orange ko q me dal rhe hain 
                    q.push({i,j});

                else if(grid[i][j] == 1)//fresh ka cnt 
                    fresh++;
            }
        }

        // No fresh oranges
        if(fresh == 0)
            return 0;

        int minutes = 0;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){//queue implement is like bfs
        //bhut sare, source se alg alg start krna hta to bfs, but yha ek hi se, 

            int sz = q.size();

            while(sz--){

                auto curr = q.front();
                q.pop();

                int r = curr.first;
                int c = curr.second;

                for(int k = 0; k < 4; k++){

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols &&
                       grid[nr][nc] == 1){

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            // Agar is minute me kuch naye oranges rotten hue,
            // tabhi minute badhao.
            if(!q.empty())
                minutes++;
        }

        if(fresh > 0)
            return -1;

        return minutes;
    }
};
