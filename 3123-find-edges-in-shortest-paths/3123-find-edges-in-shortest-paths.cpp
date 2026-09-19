class Solution {
public:

    // DOUBLE(BOTH) ENDED DIJKSTRA ALGORITHM
    
    // Double(Both) ended dijkstra : iss question me hmne src se sbhi nodes ki minimum distance nikaal li and dest se bhi sbhi nodes ki minimum distance nikaal li (src se node edge ke ek node ki minimum distance toh pta thi pr edge ke second wale node se destn tk minimum distance nhi nikaalenge baar baar isiliye dest se hi hrr ek node ki minimum distance nikaal li)

    void dijkstra(int src,vector<vector<pair<int,int>>>&adj,vector<int>&dist)
    {
        dist[src]=0;
        vector<int>explored(dist.size(),0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});

        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();

            if(explored[node])
            continue;

            explored[node]=1;

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                
                // Relaxation of edges
                if(!explored[neigh] && dist[neigh]>dist[node]+wt)
                {
                    dist[neigh] = dist[node]+wt;
                    pq.push({dist[neigh],neigh});
                }
            }
        }
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);

        dijkstra(0,adj,dist1);
        dijkstra(n-1,adj,dist2);

        vector<bool>result(edges.size(),0);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            bool flag=0;

             if(dist1[u] != INT_MAX && dist2[v] != INT_MAX && dist1[u] + wt + dist2[v] == dist1[n-1])
            {
                flag=1;
            }
             if(dist1[u] != INT_MAX && dist2[v] != INT_MAX && dist1[v] + wt + dist2[u] == dist1[n-1])
            {
                flag=1;
            }

            if(flag)
            {
                result[i]=1;
            }
        }

        return result;
    }
};