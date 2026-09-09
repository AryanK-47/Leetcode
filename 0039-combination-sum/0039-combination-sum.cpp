class Solution {
public:
    void check(vector<int>&candidates,int&target,int n,int idx,int sum,vector<int>&temp,vector<vector<int>>&ans){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target)return;

        for(int i=idx;i<n;i++){
            temp.push_back(candidates[i]);
            check(candidates,target,n,i,sum+candidates[i],temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<int>temp;
        
        int n=candidates.size();
        vector<vector<int>>ans;
        check(candidates,target,n,0,sum,temp,ans);
        return ans;
    }
};