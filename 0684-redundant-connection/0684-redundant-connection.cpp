#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    //  By Using DFS : hrr ek edge connect krne se phle check krle ke kya qo already connected toh nhi hai agr wo already connnected hue toh yhi edge cycle bnaayegi isliye usi ko return kra denge

    int dfs(int u,int v,unordered_map<int,vector<int>>&adj,vector<int>&visited)
    {
        if(u==v)
        return 1;

        visited[u] = 1;
        for(int j=0;j<adj[u].size();j++)
        {
            int neigh = adj[u][j];
            if(!visited[neigh])
            {
                if(dfs(neigh,v,adj,visited))
                return 1;
            }
        }
        return 0;
    }

       
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;

            vector<int>visited(n,0);
            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(u,v,adj,visited))
            {
                return edges[i];
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
       return {};
    }
};

