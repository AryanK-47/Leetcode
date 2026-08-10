class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>>res;
        int i=0;
        bool insert=false;
        while(i<intervals.size()){
         if(insert==false && intervals[i][0]>newInterval[0]){
            res.push_back(newInterval);
            insert=true;
         }
         res.push_back(intervals[i]);
         i++;
        }
        if (!insert) {
            res.push_back(newInterval);
        }
        vector<vector<int>>vul;
        int start1=res[0][0];
        int end1=res[0][1];
        int n=res.size();
        for(int i=1;i<n;i++){

            int start2=res[i][0];
            int end2=res[i][1];

            if(end1>=start2){
                start1=min(start1,start2);
                end1=max(end1,end2);
                continue;
            }
            vul.push_back({start1,end1});

            start1=start2;
            end1=end2;
        }
        vul.push_back({start1,end1});
        return vul;
    }
};