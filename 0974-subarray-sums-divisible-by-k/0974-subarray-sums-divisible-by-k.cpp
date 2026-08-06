class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;
        int sum=0;
        int total=0;
        freq[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;

            if(rem<0)rem=rem+k;

            if(freq.count(rem))total+=freq[rem];
            freq[rem]++;
        }
return total;
    }
};