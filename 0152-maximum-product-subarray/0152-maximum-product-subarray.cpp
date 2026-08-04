class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int besto=nums[0];
        int mini=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevmax=besto;
            int prevmini=mini;

            int v1=nums[i];
            int v2=prevmax*v1;
            int v3=prevmini*v1;

            besto=max({v1,v2,v3});
            mini=min({v1,v2,v3});
            ans=max(ans,besto);
        }
        return ans;
    }
};