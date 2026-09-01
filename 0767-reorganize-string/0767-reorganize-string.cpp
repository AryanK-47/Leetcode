class Solution {
public:
        struct cmp {
        bool operator()(pair<int, char>& a, pair<int, char>& b) {
            return a.first < b.first;  // MAX HEAP
        }
        };

    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(char i:s){
            mp[i]++;
        }
     priority_queue<
            pair<int,char>,
            vector<pair<int,char>>,
            cmp
        > pq;

        string res;
        pair<int,char>prev={0,'#'};
        
        for(auto it : mp)
            pq.push({it.second, it.first});
        
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            
            res+=curr.second;
            curr.first--;

            if(prev.first>0)pq.push(prev);

            prev=curr;
        }

        if(res.size()!=s.size()) return "";
        return res;
    }
};