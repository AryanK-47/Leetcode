class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int x:nums){
            total+=x;
        }
        int left=0;
        if(left==total-nums[left])return left;
        for(int i=1;i<n;i++){
            left+=nums[i-1];
            int right=total-nums[i]-left;
            if(left==right)return i;
        }
        return -1;
    }
};