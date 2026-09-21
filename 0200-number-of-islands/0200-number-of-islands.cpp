class Solution {
public:
    void dfs(int row , int col , vector<vector<char>>& grid ){
        int n=grid.size();
        int m=grid[0].size();

        grid[row][col]='0';

        if(row-1>=0 && grid[row-1][col]=='1')
            dfs(row-1,col,grid);
        
        if(row+1<n && grid[row+1][col]=='1')
            dfs(row+1,col,grid);

        if(col-1>=0 && grid[row][col-1]=='1')
            dfs(row,col-1,grid);

         if(col+1<m && grid[row][col+1]=='1')
            dfs(row,col+1,grid);       
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};