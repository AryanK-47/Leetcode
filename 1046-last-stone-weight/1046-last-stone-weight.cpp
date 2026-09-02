class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int curr=pq.top();
            pq.pop();
            int prev=pq.top();
            pq.pop();
            if(curr!=prev){
                pq.push(curr-prev);
            }
            else continue;
        }
        if(pq.empty())return 0;

        return pq.top();
    }
};