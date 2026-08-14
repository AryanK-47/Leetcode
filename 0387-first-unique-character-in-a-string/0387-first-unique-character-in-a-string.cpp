class Solution {
public:
    int firstUniqChar(string s) {
        
    int n=s.size();
        unordered_map<char,int>mp;

       for(int i=0;i<n;i++){
        mp[s[i]]++;
       }
       int i=0;
       while(i<n){
        if(mp[s[i]]==1)return i;
        i++;
       }
        return -1;
    }
};