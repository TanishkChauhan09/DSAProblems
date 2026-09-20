class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(int i=0;i<edges.size();i++)
        {

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        if(q.size()>1)
        return -1;

        int champion = q.front();

        vector<int>topo;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j];
                indegree[neigh]--;

                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }

        return topo.size()==n? champion: -1;

    }
};