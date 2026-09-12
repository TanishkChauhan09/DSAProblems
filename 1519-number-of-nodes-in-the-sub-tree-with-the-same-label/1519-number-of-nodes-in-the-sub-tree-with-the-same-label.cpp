class Solution {
public:
    
    vector<int>dfs(int node,vector<vector<int>>&adj,int parent,string &labels,vector<int>&results)
    {
        vector<int>nodevect(26,0);
        int nodelabel_char = labels[node]-'a';
        nodevect[nodelabel_char]=1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(neigh==parent)
            continue;

            vector<int>childvect = dfs(neigh,adj,node,labels,results);

            for(int i=0;i<26;i++)
            {
                nodevect[i]+=childvect[i];
            }
        }

        results[node] = nodevect[nodelabel_char];

        return nodevect;

    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>results(n,0);
        
        dfs(0,adj,-1,labels,results);

        return results;
        
    }
};