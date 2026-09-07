class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        int m = tasks.size();

        unordered_map<char,int> freq;
        unordered_map<char,int> free;

        for(int i = 0; i < m; i++){
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        priority_queue<pair<int,char>> pq;

        for(auto i : freq){
            pq.push({i.second, i.first});
        }

        int seat = 1;

        while(!pq.empty()){

            vector<pair<int,char>> sideline;

            while(!pq.empty()){

                auto group = pq.top();
                pq.pop();

                int group_freq = group.first;
                char group_child = group.second;

                if(free[group_child] <= seat){

                    if(group_freq > 1){
                        pq.push({group_freq - 1, group_child});
                    }

                    free[group_child] = seat + n + 1;

                    break;
                }
                else{
                    sideline.push_back(group);
                }
            }

            for(auto i : sideline){
                pq.push(i);
            }

            seat++;
        }

        return seat - 1;
    }
};