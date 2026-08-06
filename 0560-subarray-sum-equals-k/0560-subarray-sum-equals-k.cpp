class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        int sum=0;
        freq[0]=1;
        int res=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int ques=sum-k;
            if(freq.count(ques))res+=freq[ques];
            freq[sum]++;
        }
        return res;

    }
};