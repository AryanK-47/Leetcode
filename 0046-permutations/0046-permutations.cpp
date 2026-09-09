class Solution {
public:

    void check(vector<int>&nums,int n,vector<bool>&used,
        vector<vector<int>>&ans,
        vector<int>&temp){

            if(temp.size()==n){
                ans.push_back(temp);
                return;
            }

            for(int i=0;i<n;i++){
                    if(used[i]==true)continue;

                    used[i]=true;
                    temp.push_back(nums[i]);
                    check(nums,n,used,ans,temp);
                    temp.pop_back();
                    used[i]=false;

            }
        }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool>used(n,false);
        vector<vector<int>>ans;
        vector<int>temp;
        check(nums,n,used,ans,temp);
        return ans;
    }
};