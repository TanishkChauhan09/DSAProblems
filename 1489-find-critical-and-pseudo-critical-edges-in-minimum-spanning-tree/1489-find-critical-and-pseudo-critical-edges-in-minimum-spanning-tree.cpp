class Solution {
public:

    int findparent(int u,vector<int>&parent)
    {
        // Base condition
        if(u==parent[u])
        return u;

        // path compression
        return parent[u] = findparent(parent[u],parent);
    }

    void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int Pu = findparent(u,parent);
        int Pv = findparent(v,parent);

        if(rank[Pu]>rank[Pv])
          parent[Pv] = Pu;
        else if(rank[Pu]<rank[Pv])
          parent[Pu] = Pv;
        else
        {
            rank[Pu]++;
            parent[Pv] = Pu;
        }    
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        // initilially eveyone is its own parent
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0;i<edges.size();i++)
        {
            edges[i].push_back(i);
        }

        // sort the edges
        sort(edges.begin(), edges.end(),
             [](auto& a, auto& b) { return a[2] < b[2]; });

        vector<int>pushed_edges;

        int cost=0;
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            int idx = edges[i][3];

            if(findparent(u,parent)!=findparent(v,parent))
            {
                cost+=wt;
                unionbyrank(u,v,parent,rank);
                pushed_edges.push_back(idx);
            }
        }
        vector<int>critical;
        vector<int>Pcritical;

        for(int i=0;i<edges.size();i++)
        {
            vector<int>parent2(n,0);
            vector<int>rank2(n,0);
            for(int k=0;k<n;k++)
            {
                parent2[k] = k;
            }
            
            int new_cost=0;
            int mst_idx = edges[i][3];
            int comp = n;   // ADDED

            for(int j=0;j<edges.size();j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                int idx = edges[j][3];

                if(idx==mst_idx)
                continue;

                if(findparent(u,parent2)!=findparent(v,parent2))
                {
                    new_cost+=wt;
                    unionbyrank(u,v,parent2,rank2);
                    comp--;      // ADDED
                }
            }

            // ADDED: If graph disconnected → mark as INF
            if(comp != 1) new_cost = 1e8;

            // --- CRITICAL check (skip case) ---
            if(new_cost > cost)
            {
                // if skipping increases cost OR disconnects graph -> critical
                critical.push_back(mst_idx);
            }
            else {
                // new_cost <= cost -> NOT critical
                // Now test FORCED-INCLUDE for pseudo-critical
                vector<int> parent3(n,0);
                vector<int> rank3(n,0);
                for(int k=0;k<n;k++) parent3[k]=k;

                int forced_cost = 0;
                int edges_used = 0;

                // Force include current edge first
                int fu = edges[i][0];
                int fv = edges[i][1];
                int fwt = edges[i][2];

                // include it
                if(findparent(fu,parent3) != findparent(fv,parent3)) {
                    unionbyrank(fu,fv,parent3,rank3);
                    forced_cost += fwt;
                    edges_used++;
                }

                // Now run Kruskal normally (do not skip any edge)
                for(int j=0;j<edges.size();j++)
                {
                    int u = edges[j][0];
                    int v = edges[j][1];
                    int wt = edges[j][2];
                    int idx = edges[j][3];

                    if(findparent(u,parent3) != findparent(v,parent3))
                    {
                        unionbyrank(u,v,parent3,rank3);
                        forced_cost += wt;
                        edges_used++;
                    }
                }

                // If we could form MST and cost equals original -> pseudo-critical
                if(edges_used == n-1 && forced_cost == cost)
                {
                    Pcritical.push_back(mst_idx);
                }
            }
        }
        
        vector<vector<int>>ans;
        ans.push_back(critical);
        ans.push_back(Pcritical);

        return ans;
    }
};