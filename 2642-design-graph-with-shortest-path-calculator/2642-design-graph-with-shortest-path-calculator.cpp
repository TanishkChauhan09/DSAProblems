class Graph {
public:
    
    vector<vector<pair<int,int>>>adj;
    int components;

    Graph(int n, vector<vector<int>>& edges) {

         adj.resize(n);
         components = n;

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v,wt});
        }
        
    }
    
    void addEdge(vector<int> edge) {

         int u = edge[0];
         int v = edge[1];
         int wt = edge[2];

         adj[u].push_back({v,wt});
        
    }
    
    int shortestPath(int node1, int node2) {

        int src = node1;
        vector<int>dist(components,INT_MAX);
        vector<int>visited(components,0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        dist[src]=0;
        pq.push({0,src});

        while(!pq.empty())
        {
            int node = pq.top().second;
            pq.pop();

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;

                // Relaxation of edges
                if(!visited[neigh] && dist[neigh]>dist[node]+wt)
                {
                    dist[neigh] = dist[node]+wt;
                    pq.push({dist[node]+wt , neigh});
                }
            }
        }
        if(dist[node2]==INT_MAX)
        return -1;

        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */