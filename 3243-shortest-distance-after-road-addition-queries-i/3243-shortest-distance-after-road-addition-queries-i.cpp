class Solution {
public:
   
    int shortestDistBFS(int src,vector<vector<int>>&adj)
    {
        int n = adj.size();
        vector<int>dist(adj.size(),INT_MAX);
        dist[src] = 0;

        queue<int>q;
        q.push(src);

        vector<int>visited(adj.size(),0);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            if(node == n-1)
            return dist[n-1];

            if(visited[node])
            continue;

            visited[node] = 1;

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j];
                dist[neigh] = min(dist[neigh] , 1+dist[node]);
                q.push(neigh);
            }
        }
        return dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++)
        {
            int u = i;
            int v = i+1;

            adj[u].push_back(v);
        }

        vector<int>ans(queries.size(),0);
        
        for(int i=0;i<queries.size();i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            adj[u].push_back(v);

            int dist = shortestDistBFS(0,adj);
            ans[i] = dist;
        }

        return ans;
        
    }
};