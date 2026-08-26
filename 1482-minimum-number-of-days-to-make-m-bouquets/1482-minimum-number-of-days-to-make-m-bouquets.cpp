class Solution {
public:
int check(vector<int>& bloomDay,int k,int mid){
    int count=0;
    int bouq=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i]<=mid){
            count++;
            if(count==k){
                bouq++;
                count=0;
            }
        }
        else count=0;
    }
    return bouq;
}
    int minDays(vector<int>& bloomDay, int m, int k) {

        int n=bloomDay.size();
        if((long long)k*m>n)return -1;

        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        
        while(low<=high){
            
            int mid=(low+high)/2;
            int flower=check(bloomDay,k,mid);
            
            if(flower<m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};