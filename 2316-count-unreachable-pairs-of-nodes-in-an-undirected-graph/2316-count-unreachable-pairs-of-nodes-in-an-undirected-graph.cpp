class Solution {
public:

    void dfs(int node,vector<vector<int>>&adj,vector<int>&indfs,int &count)
    {
        indfs[node]=1;
        count++;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(!indfs[neigh])
            {
                dfs(neigh,adj,indfs,count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>indfs(n,0);
        vector<int>arr;

        for(int i=0;i<n;i++)
        {

            if(!indfs[i])
            {
                
                int count=0;

                dfs(i,adj,indfs,count);

                arr.push_back(count);
            }
        }

        long long totalsum = 0;
        for(int i=0;i<arr.size();i++)
        {
            totalsum+=arr[i];
        }

        long long res=0;
        for(int i=0;i<arr.size();i++)
        {
            res += (long long)arr[i] * (totalsum-arr[i]);
        }

        return res/2;
    }
};