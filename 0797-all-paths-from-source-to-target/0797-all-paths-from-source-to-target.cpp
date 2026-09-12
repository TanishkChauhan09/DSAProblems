class Solution {
public:

    void dfs(int node,vector<vector<int>>&adj,vector<int>&temp,vector<vector<int>>&ans,int dest)
    {
        temp.push_back(node);

        if(node==dest)
        {
            ans.push_back(temp);
        }

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];
            dfs(neigh,adj,temp,ans,dest);
        }

        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>ans,adj(n);

        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
               adj[i].push_back(graph[i][j]);
        }

        vector<int>temp;

        dfs(0,adj,temp,ans,n-1);

        return ans;

    }
};