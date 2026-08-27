class Solution {
public:
    int check(vector<int>&weights,int mid){
        int day=1;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                day++;
                sum=weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
    int low=*max_element(weights.begin(),weights.end());
    int high=0;
    for(int i=0;i<weights.size();i++){
        high+=weights[i];
    }
    int res=0;
    while(low<=high){
        int mid=(low+high)/2;
        int user=check(weights,mid);
        if(user<=days){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
    }
};