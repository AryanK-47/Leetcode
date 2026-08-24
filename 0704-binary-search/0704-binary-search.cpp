class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int left=0;
        int high=nums.size()-1;
        if(nums.size()==1 && nums[0]==target) return 0;
        while(left<=high){
            int mid=(left+high)/2;
            if(nums[mid]<target){
                left=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else return mid;
        }
        return -1;
    }
};