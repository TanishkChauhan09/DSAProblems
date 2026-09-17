class Solution {
public:

    int dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&path)
    {
        visited[node]=1;
        path[node]=1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];
            if(!visited[neigh])
            {
                if(dfs(neigh,adj,visited,path))
                return 1;
            }
            if(path[neigh])
            {
                return 1;
            }
        }

        path[node]=0;
        return 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
       int n = graph.size();
       vector<vector<int>>adj(n);

       for(int i=0;i<n;i++)
       {
          for(int j=0;j<graph[i].size();j++){
            int u = i;
            int v = graph[i][j];

            adj[u].push_back(v);
          }
       }

       vector<int>visited(n,0);
       vector<int>path(n,0);

       for(int i=0;i<n;i++)
       {
            if(!visited[i])
            {
                dfs(i,adj,visited,path);
            }
       }
       vector<int>result;
       for(int i=0;i<path.size();i++)
       {
          if(!path[i])
          {
              result.push_back(i);
          }
       }

       return result;
   }
};