class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&color){
        for(int i=0;i<graph[node].size();i++){
            int nb=graph[node][i];

            if(color[nb]==-1){
                color[nb]=1-color[node];
                    if(dfs(nb,graph,color)==false)return false;
            }
            else if(color[nb]==color[node])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(dfs(i,graph,color)==false)return false;
            }
        }
        return true;
    }
};