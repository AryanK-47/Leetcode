class Solution {
public:
    

    bool bfs(int n,int row,int col,vector<vector<int>>& grid,int mid,vector<vector<bool>>&vis){

        if(row<0 || row>=n || col<0 || col>=n)return false;

        if(grid[row][col] > mid)return false;

        if(vis[row][col]==true) return false;

        if(row==n-1 && col==n-1)return true;

        vis[row][col]=true;

        if(bfs(n,row-1,col,grid,mid,vis)) return true;

        if(bfs(n,row+1,col,grid,mid,vis)) return true;

        if(bfs(n,row,col-1,grid,mid,vis)) return true;

        if(bfs(n,row,col+1,grid,mid,vis)) return true;

        return false;

    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int low=0;
        int high=n*n -1;

        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;

            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if(bfs(n,0,0,grid,mid,vis)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};