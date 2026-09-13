class Solution {
public:
   
    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&visited,int &ans)
    {
        visited[node]=1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j].first;
            int wt = adj[node][j].second;
            
            ans = min(ans,wt);

            if(!visited[neigh])
            {
                dfs(neigh,adj,visited,ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>>adj(n);
        vector<int>distance(n,INT_MAX);

        for(int i=0;i<roads.size();i++)
        {
             int u = roads[i][0]-1;
             int v = roads[i][1]-1;
             int wt = roads[i][2];

             adj[u].push_back({v,wt}); 
             adj[v].push_back({u,wt});    
        }
         
        int ans = INT_MAX;
        vector<int>visited(n,0);

        dfs(0,adj,visited,ans);

        return ans;
            
    }
};