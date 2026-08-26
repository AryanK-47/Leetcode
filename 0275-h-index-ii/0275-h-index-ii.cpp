class Solution {
public:
    bool check(vector<int>&arr,int n,int mid){
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]>=mid){
                count++;
                if(count>=mid)return true;
            }
        }
        return false;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0;
        int high=n;
        int res=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(citations,n,mid)){
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return res;
    }
};