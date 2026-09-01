class Solution {
public:
        struct cmp {
        bool operator()(pair<int, vector<int>>& a,
                        pair<int, vector<int>>& b) {
            return a.first < b.first;  // MAX HEAP
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
     priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            cmp
        > pq;

        for(auto i:points){
            int dist=i[0]*i[0] + i[1]*i[1];
            pq.push({dist,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};