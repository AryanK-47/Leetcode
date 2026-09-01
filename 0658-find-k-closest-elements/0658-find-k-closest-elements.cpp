class Solution {
public:
        struct cmp {
        bool operator()(pair<int,int>& a,
                        pair<int,int>& b) {
                            if(a.first!=b.first){
            return a.first < b.first;  // MAX HEAP
        }
        return a.second<b.second;
                        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            cmp
        > pq;

        for(int i:arr){
            int dist=abs(i-x);
            pq.push({dist,i});
            if(pq.size()>k)pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};