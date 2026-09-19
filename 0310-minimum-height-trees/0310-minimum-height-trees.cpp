class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n==1)
        return {0};
        
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[u]++;
            indegree[v]++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }

        while(n>2)
        {
            int size = q.size();

            n = n-size;

            while(size--)
            {
    
                int node = q.front();
                q.pop();

                for(int j=0;j<adj[node].size();j++)
                {
                    int neigh = adj[node][j];
                    indegree[neigh]--;

                    if(indegree[neigh]==1)
                    {
                        q.push(neigh);
                    }
                }
            }
        }

        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;

    }
};