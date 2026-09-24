class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        dist[0][0]=0;

         priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        pq.push({0,{0,0}});

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        while(!pq.empty()){
             auto current=pq.top();
             pq.pop();

             int effort=current.first;

             int row=current.second.first;
             int col=current.second.second;

             if(row==n-1 && col==m-1) return effort;

             for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr >=0 && nr<n && nc>=0 && nc<m){
                    int diff=abs(heights[row][col] - heights[nr][nc]);
                    int newf=max(effort,diff);

                    if(newf<dist[nr][nc]){
                        dist[nr][nc]=newf;
                        pq.push({newf,{nr,nc}});
                    }
                }
             }
        }
        return 0;
    }
};