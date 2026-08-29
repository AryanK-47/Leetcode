class Solution {
public:
    int check(vector<int>&nums,int mid){
        int kk=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                kk++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return kk;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        for(int i=0;i<n;i++){
            high+=nums[i];
        }
        int res=0;
        while(low<=high){
            int mid=(low+high)/2;
            int user=check(nums,mid);
            if(user>k){
                low=mid+1;
                
            }
            else{
                res=mid;
                high=mid-1;
                
            }
        }
        return res;
    }
};