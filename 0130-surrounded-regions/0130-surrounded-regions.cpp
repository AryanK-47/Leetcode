class Solution {
public:
    void dfs(int row , int col , vector<vector<char>>& grid ){
        int n=grid.size();
        int m=grid[0].size();

        grid[row][col]='S';

        if(row-1>=0 && grid[row-1][col]=='O')
            dfs(row-1,col,grid);
        
        if(row+1<n && grid[row+1][col]=='O')
            dfs(row+1,col,grid);

        if(col-1>=0 && grid[row][col-1]=='O')
            dfs(row,col-1,grid);

         if(col+1<m && grid[row][col+1]=='O')
            dfs(row,col+1,grid);       
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<m;i++){
            if(board[0][i]=='O')dfs(0,i,board);

            if(board[n-1][i]=='O')dfs(n-1,i,board);
        }

        for(int i=0;i<n;i++){
            if(board[i][0]=='O')dfs(i,0,board);

            if(board[i][m-1]=='O')dfs(i,m-1,board);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='O')board[i][j]='X';

                else if(board[i][j]=='S')board[i][j]='O';
            }
        }
    }
};