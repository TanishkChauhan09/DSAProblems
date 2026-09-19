class Solution {
public:

    // edges ko revers kr diya child se ancestors ki taraf

    // ab he node se dfs chalaaya jiss bhi node pr jaa skta hoon whi mere ancestors honge

    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited)
    {
        visited[node] = 1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];
            if(!visited[neigh])
            {
                dfs(neigh,adj,visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            // Reverse the edges
            adj[v].push_back(u);  // v--->u
        }

        vector<vector<int>>result; 

        for(int i=0;i<n;i++)
        {
            vector<int>visited(n,0);
            vector<int>ancestors;

            dfs(i,adj,visited);

            for(int j=0;j<n;j++)
            {
                if(visited[j] && i!=j)
                {
                    ancestors.push_back(j);
                }
            }
            result.push_back(ancestors);
        }
        
        return result;

    }
};