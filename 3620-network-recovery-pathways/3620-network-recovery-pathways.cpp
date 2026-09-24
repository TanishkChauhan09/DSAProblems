class Solution {
public:
   
    typedef long long LL;

    bool checkPossible(int n, vector<vector<pair<int,int>>>&adj, LL mid, LL k)
    {
        vector<LL>dist(n,LLONG_MAX);
        dist[0] = 0;

        priority_queue<pair<LL,int>, vector<pair<LL,int>>, greater<pair<LL,int>>> pq; 
        pq.push({0,0});

        while(!pq.empty())
        {
            int node = pq.top().second;
            LL distance = pq.top().first;
            pq.pop();

            if(distance > k)  // means abhi n-1 pr pahuchne se phle hi k se bdi distance nikal gyi 
                return 0;

            if(node == n-1)
                return 1;  

            if(dist[node] < distance)
            continue;

            // relaxation of edges
            for(int j=0; j<adj[node].size(); j++)
            {
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;

                if(wt < mid)
                 continue;
                
                if(distance + LL(wt) < dist[neigh])
                {
                    dist[neigh] = distance + wt;
                    pq.push({dist[neigh] , neigh});
                }
            }

        }

        return 0;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
        int start = INT_MAX, end = INT_MIN;
        int n = online.size();   // total no. of nodes
         
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            if(!online[u] || !online[v])
              continue;

            adj[u].push_back({v,wt}); 
            
            start = min(start , wt);
            end = max(end , wt);
        }

        int ans = -1;

        while(start<=end)
        {
            int mid = start+(end-start)/2;

            if(checkPossible(n,adj,mid,k))
            {
                ans = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }

        return ans;
    }
};