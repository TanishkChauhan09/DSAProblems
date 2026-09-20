class Solution {
public:

    int dijkstra(vector<vector<int>>&edges,int src,int dest,int n)
    {
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            if(wt!=-1)
            {
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});

        vector<int>explored(n,0);

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

                if(!explored[neigh] && dist[neigh]>dist[node]+wt)
                {
                    dist[neigh] = dist[node]+wt;
                    pq.push({dist[neigh],neigh});
                }
            }
        } 

        return dist[dest];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {

        int currGraphDist = dijkstra(edges,source,destination,n);

        if(currGraphDist < target)
        {
            return {};
        }

        bool flag = (currGraphDist == target);

        // means minimum distance already aayi hui hai kisi bhi -1 edge ko kisi me bhi change mt kro prr unn sbko maximum wt ka bna denge taaki unse na jaapaaye 
        if(flag==1) 
        {
            for(int j=0;j<edges.size();j++)
            {
                if(edges[j][2]==-1)
                {
                    edges[j][2] = 2e9;
                }
            }

            return edges;
        }

        for(int i=0;i<edges.size();i++)
        {
            vector<int>&edge = edges[i];
            
            if(edge[2]==-1)
            {
                if(flag==true)
                {
                    edge[2] = 2e9;
                }
                else
                {
                    edge[2] = 1;
                }

                if(flag!=1)
                {
                    int graphDist = dijkstra(edges,source,destination,n);

                    if(graphDist <= target)
                    {
                        flag=1;
                        edge[2] += (target-graphDist);
                    }
                }
            }
        }

        if(flag==0)
        return {};

        return edges;
        
    }
};