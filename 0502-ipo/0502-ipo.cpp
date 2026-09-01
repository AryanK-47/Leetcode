class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>pro;
        for(int i=0;i<n;i++){
            pro.push_back({capital[i],profits[i]});
        }
        sort(pro.begin(),pro.end());

        priority_queue<int>pq;
        int ind=0;
        while(k--){
            while(ind<n && pro[ind].first<=w){
                pq.push(pro[ind].second);
                ind++;
            }
            if(pq.empty())return w;

            w+=pq.top();
            pq.pop();
        }
        return w;

    }
};