class Solution {
public:
    int check(vector<vector<int>>& matrix,int n,int m,int mid){
        int row=n-1;
        int col=0;
        long long count=0;
        while(col<m && row>=0){
            if(matrix[row][col]<=mid){
                count+=row+1;
                col++;
            }
            else row--;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        int res=0;
        while(low<=high){
            int mid=(low+high)/2;
            int user= check(matrix,n,m,mid);
            if(user<k)low=mid+1;
            else{
                res=mid;
                high=mid-1;
            }

        }
        return res;
    }
};