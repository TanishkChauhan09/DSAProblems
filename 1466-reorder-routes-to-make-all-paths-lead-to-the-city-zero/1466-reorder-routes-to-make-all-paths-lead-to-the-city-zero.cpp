class Solution {
public:

    void dfs(int node,vector<vector<pair<int,int>>>&adj,vector<int>&visited,int &ans)
    {
        visited[node]=1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j].first;
            int realornotedge = adj[node][j].second;

            if(!visited[neigh])
            {
                if(realornotedge)
                {
                    ans+=1;
                }

                dfs(neigh,adj,visited,ans);
            } 
        }
        
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<int>visited(n,0);
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<connections.size();i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        int ans=0;
        dfs(0,adj,visited,ans);

        return ans;

    }
};