class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int besto=nums[0];
        int ans=abs(nums[0]);
        int mini=nums[0];
        
        for(int i=1;i<n;i++){
            int v1=nums[i];

            mini=min(v1,v1+mini);
            besto=max(v1,v1+besto);
            ans=max({ans,besto,-mini});
        }
        return ans;
    }
};