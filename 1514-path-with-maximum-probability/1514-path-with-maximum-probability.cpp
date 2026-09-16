class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double wt = succProb[i];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<double> dist(n, 0.0);

        priority_queue<pair<double,int>> pq;

        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(node == end_node)
                return prob;

            if(prob < dist[node])
                continue;

            for(int j = 0; j < adj[node].size(); j++)
            {
                int neigh = adj[node][j].first;
                double wt = adj[node][j].second;

                double newProb = prob * wt;

                if(newProb > dist[neigh])
                {
                    dist[neigh] = newProb;
                    pq.push({newProb, neigh});
                }
            }
        }

        return 0.0;
    }
};