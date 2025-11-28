class Solution {
public:
    
    long long dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&values,int k,int &count)
    {
        long long sum = values[node];
        // traversing the node's neighbour and going in depth
        for(int j=0;j<adj[node].size();j++)
        {
            int neighbour = adj[node][j];
        
            if(neighbour==parent) 
            continue;

            long long childsum = dfs(neighbour,node,adj,values,k,count);
            
            sum = sum+childsum;
        
        }

            if(sum%k==0)
            {
                count++;
                return 0;
            }

            return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {

        // making the adjacency list
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        
        int count=0;

        dfs(0,-1,adj,values,k,count);

        return count;

    }
};