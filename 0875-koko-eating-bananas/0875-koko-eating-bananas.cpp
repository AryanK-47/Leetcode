class Solution {
public:
    long long check(vector<int>& piles,int n,int speed){
        long long h=0;
        for(int i=0;i<n;i++){
            h+=piles[i]/speed;
            if(piles[i]%speed!=0)h++;
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(piles[i]>high)high=piles[i];
        }
        while(low<=high){
            int mid=(low+high)/2;
            long long hour=check(piles,n,mid);
            if(hour>h)low=mid+1;
            else{
                res=mid;
                high=mid-1;
            }
        }
        return res;
    }
};