class Solution {
public:
    
    // hr node se 0 pahuch paa rhe hai ya nhi iske liye hh node de dfs/bfs lgaana pdega toh isss se accha kyu na edges ko reverse ke le and ye dekh le ke kya 0 se hrr node pe pahuch paa rha hoon ya nhi(OPTIMIZATION)

    // question dekh ke pta hi chal rha hai ke binary search on answer lgeega



    bool canWeReach(vector<vector<pair<int,int>>>&adj , int mid)
    {
        int n = adj.size();
        queue<int>q;
        q.push(0);
        vector<int>visited(n,0);
        visited[0]=1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j].first;
                int wt  = adj[node][j].second;

                if(!visited[neigh] && wt<=mid)
                {
                    visited[neigh]=1;
                    q.push(neigh);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
               return 0;
        }

        return 1;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        
        vector<vector<pair<int,int>>>adj(n);
        int maxWt = 0;

        // Adjacency list 
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[v].push_back({u,wt});  // v--->u reversed edge
            maxWt = max(maxWt,wt);
        }

        int start=0, end = maxWt;
        int ans = INT_MAX;

        while(start<=end)
        {
            int mid = start+(end-start)/2;

            if(canWeReach(adj,mid)==true)
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
       
       return ans==INT_MAX ? -1 : ans;
    }
};