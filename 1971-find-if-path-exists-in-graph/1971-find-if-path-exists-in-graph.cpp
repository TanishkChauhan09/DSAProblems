class Solution {
public:
    
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited)
    {
        visited[node]=1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neighbour = adj[node][j];
            if(!visited[neighbour])
            {
                dfs(neighbour,adj,visited);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>visited(n,0); 
        dfs(source,adj,visited);

        if(visited[source] && visited[destination])
            return 1;

         return 0; 
    }
};