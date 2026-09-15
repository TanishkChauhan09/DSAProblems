class DSU{

    public:
    
    vector<int>parent;
    vector<int>rank;
    int components;
    
    DSU(int n){
        
        parent.resize(n+1);
        rank.resize(n+1);
        components = n;
        for(int i=1;i<=n;i++)
        {
            parent[i] = i;
        }
    }

    int findparent(int u)
    {
        if(u==parent[u])
        return u;

        return parent[u] = findparent(parent[u]);
    }

    void unionbyrank(int u,int v)
    {
        int Pu = findparent(u);
        int Pv = findparent(v);

        if(Pu==Pv)
        return;

        if(rank[Pu]<rank[Pv])
        {
            parent[Pu] = Pv;
        }
        else if(rank[Pu]>rank[Pv])
        {
            parent[Pv] = Pu;
        }
        else
        {
            rank[Pu]++;
            parent[Pv] = Pu;
        }

        components--;
    }
    
};

class Solution {
public:
     
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        DSU Alice(n);
        DSU Bob(n);

        auto lambda = [](vector<int>&v1,vector<int>&v2)
        {
            return v1[0]>v2[0];
        };

        sort(edges.begin(),edges.end(),lambda);

        int ans = 0;

        for(int i=0;i<edges.size();i++)
        {
            int type = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if(type==3)
            {
                bool doesEdgeAdded = 0;

                if(Alice.findparent(u)!=Alice.findparent(v))
                {
                    doesEdgeAdded=1;
                    Alice.unionbyrank(u,v);
                }
                if(Bob.findparent(u)!=Bob.findparent(v))
                {
                    doesEdgeAdded=1;
                    Bob.unionbyrank(u,v);
                }
                if(doesEdgeAdded == 1)
                {
                    ans++;
                }
            }
            else if(type==1)
            {
                if(Alice.findparent(u)!=Alice.findparent(v))
                {
                    Alice.unionbyrank(u,v);
                    ans++;
                }
            }
            else
            {
                if(Bob.findparent(u)!=Bob.findparent(v))
                {
                    Bob.unionbyrank(u,v);
                    ans++;
                }
            }
        }
        
        int totalgivenedges = edges.size();
        if(Alice.components==1 && Bob.components==1)
        return totalgivenedges-ans;

        return -1;
    }
};