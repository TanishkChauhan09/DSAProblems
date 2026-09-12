class Solution {
public:
    
    // labels string ko as a refernece pass krna hai MLE se bchne ke liye
    void dfs(int node,vector<vector<int>>&adj,int parent,string &labels,vector<int>&results,vector<int>&counts)
    {
        
        int nodelabel_char = labels[node]-'a';
        counts[nodelabel_char]++;

        int before = counts[nodelabel_char];
        
        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(neigh==parent)
               continue;

            dfs(neigh,adj,node,labels,results,counts);

        }

        results[node] = counts[nodelabel_char]-before+1;

    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string &labels) {

        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>results(n,0);
        vector<int>counts(26,0);
        
        dfs(0,adj,-1,labels,results,counts);

        return results;
        
    }
};