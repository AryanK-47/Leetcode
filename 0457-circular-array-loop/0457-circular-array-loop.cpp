class Solution {
public:
int next(vector<int>&nums,int i){
    int n=nums.size();
    return((i+nums[i])%n +n)%n;
    
}
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            bool forward=nums[i]>0;
            int slow=i;
            int fast=i;

            while((nums[fast]>0)==forward && (nums[next(nums,fast)]>0)==forward){
                slow=next(nums,slow);
                fast=next(nums,next(nums,fast));
                if(slow==fast){
                if(slow==next(nums,slow))break;
                return true;
            }
            }
        }
        return false;
    }
};