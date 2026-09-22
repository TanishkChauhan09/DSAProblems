class Solution {
public:

    // if there are n vertices in a graph then there must be nC2 edges which is n(n-1)/2 .

    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited,int &v,int &e)
    {
        visited[node] = 1;
        v++;
        e += adj[node].size();

        // traversing on the neighbors
        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(!visited[neigh])
            {
                dfs(neigh,adj,visited,v,e);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        // making the adjacency list
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        // graph will be in components 
        vector<int>visited(n,0);

        for(int i=0;i<n;i++)    // O( n*(V+E) )
        {
            if(!visited[i])
            {
                int v = 0;
                int e = 0;

                dfs(i,adj,visited,v,e);

                if( v*(v-1) == e)  // same edge do vertices ke liye add hojaayegi isiliye edges(e) me 2 se divide krta pr isme hmne dusre taraf ka 2 hta diya jiss se dono balance hogye   (v*(v-1)/2 == e/2) 
                {
                    ans++;
                }
            }
        }

        return ans;
        
    }
};