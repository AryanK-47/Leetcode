class Solution {
public:
    int check(int m,int n,int mid){
        int count=0;
        int row=m;
        int col=1;
        while(row>=1 &&col<=n){
            if(mid>=row*col){
                count+=row;
                col++;
            }
            else row--;
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int low=1;
        int high=m*n;
        int res=0;
        while(low<=high){
            int mid=(low+high)/2;
            int user=check(m,n,mid);
            if(user<k)low=mid+1;
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};