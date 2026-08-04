class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int besto=0;
        int ans=INT_MIN;
        if(nums.size()==1)return nums[0];
        for(int i=0;i<nums.size();i++){
            int v1=besto+nums[i];
            int v2=nums[i];
            besto=max(v1,v2);
            ans=max(ans,besto);
        }
        return ans;
    }
};