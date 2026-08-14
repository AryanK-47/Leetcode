class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        int res=0;
        bool odd=false;
        for(auto i:s){
            freq[i]++;
        }
        for(auto[c,count]:freq){
            res+=(count/2)*2;

            if(count%2==1)odd=true;
        }
        if(odd)res++;
        return res;
    }
};