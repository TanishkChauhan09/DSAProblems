class Solution {
public:

   typedef long long LL;
    
    void dfs(int node, unordered_map<int,vector<int>>&adj,unordered_set<int>&visited)
    {
        visited.insert(node);
        for(int neigh : adj[node])
        {
            if(visited.find(neigh)==visited.end())
            {
                dfs(neigh,adj,visited);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        unordered_map<int,vector<int>>adj;
        int n = bombs.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r = bombs[i][2];

                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];

                LL dist = ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
                if(LL(r*r)>=dist)
                {
                    adj[i].push_back(j);
                }
            }
        }

        unordered_set<int>visited;
        int ans=0;

        for(int i=0;i<n;i++)
        {
             dfs(i,adj,visited);
             int count = visited.size();
             visited.clear();
             ans = max(ans,count);
        }

        return ans;
        
    }
};