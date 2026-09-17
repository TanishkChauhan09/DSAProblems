class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<vector<int>>adj(n);

        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int n_i = adj[i].size();
                int n_j = adj[j].size();

                int total = n_i+n_j;

                for(int k=0;k<adj[i].size();k++)
                {
                    if(adj[i][k]==j)
                    {
                        total-=1;
                        break;
                    }
                }
                ans = max(ans,total);
            }
        }
        return ans;
    }
};