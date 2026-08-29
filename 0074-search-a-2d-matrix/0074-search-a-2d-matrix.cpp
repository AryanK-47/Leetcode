class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        int res=0;
        int low=0;
        int high=matrix.size()*matrix[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/n;
            int col=mid%n;
            res=matrix[row][col];
            if(res==target)return true;
            else if(res<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
    
};