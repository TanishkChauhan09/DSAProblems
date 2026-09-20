class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // initially assume from source we have infinite distance to every other node
        vector<int>dist1(n,INT_MAX);
        // this is to store the second maximum distance possible from source to node 
        // and second maximum me src se src tk ki distance 0 nhi hogi wo to sirf first time me hogi
        // isiliye dist2[src] me 0 nhi initialise bhi nhi kiya hai
        vector<int>dist2(n,INT_MAX);

        dist1[0]=0; 
        // min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});

        while(!pq.empty())
        {
            int node = pq.top().second;
            int timer = pq.top().first;
            pq.pop();

            if(node==n-1 && dist2[n-1]!=INT_MAX)
            return dist2[n-1];

            int div = timer/change;
            
            if(div%2==0) //even ->green color safe ,can leave easily
            {
                timer = timer;
            }
            else // odd-> red color, so get the next value till it remain red
            {
                timer = (div+1)*change;
            }

            // start traversing the neighbour
            for(int j=0;j<adj[node].size();j++)
            {
                int neighbour = adj[node][j];

                // if(dist1[node]==INT_MAX)
                // continue;

                int distance = timer+time;  // this is a given time for each edge to traverse

                if (distance < dist1[neighbour]) 
                {
                    dist2[neighbour] = dist1[neighbour];
                    dist1[neighbour] = distance;
                    pq.push({distance, neighbour});
                } 
                else if (distance > dist1[neighbour] && distance < dist2[neighbour]) 
                {
                    dist2[neighbour] = distance;
                    pq.push({distance, neighbour});
                }
            }
        }

        return -1;
    }
};