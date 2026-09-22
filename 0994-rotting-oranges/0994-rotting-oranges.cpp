class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;

        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
                if(grid[i][j]==1)fresh++;
            }
        }
        int time=0;

        while(!q.empty() && fresh>0){
            int s=q.size();
            time++;
            while(s--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();

                  if(row-1 >= 0 && grid[row-1][col] == 1) {
                    grid[row-1][col] = 2;
                    fresh--;
                    q.push({row-1, col});
                }

                
                if(row+1 < n && grid[row+1][col] == 1) {
                    grid[row+1][col] = 2;
                    fresh--;
                    q.push({row+1, col});
                }

                
                if(col-1 >= 0 && grid[row][col-1] == 1) {
                    grid[row][col-1] = 2;
                    fresh--;
                    q.push({row, col-1});
                }

               
                if(col+1 < m && grid[row][col+1] == 1) {
                    grid[row][col+1] = 2;
                    fresh--;
                    q.push({row, col+1});
                }
        }
      
        }

        if(fresh>0)return -1;

        return time;
    }
};