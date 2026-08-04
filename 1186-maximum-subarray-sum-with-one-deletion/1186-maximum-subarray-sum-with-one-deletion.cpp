class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int nodelete=nums[0];
        int onedelete=INT_MIN;
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int prevdelete=nodelete;
            int prevonedelete=onedelete;

            nodelete=max(prevdelete+nums[i],nums[i]);

            onedelete=max(prevdelete,prevonedelete==INT_MIN?INT_MIN:prevonedelete+nums[i]);
            ans=max({ans,nodelete,onedelete});
        }
        return ans;
    }
};