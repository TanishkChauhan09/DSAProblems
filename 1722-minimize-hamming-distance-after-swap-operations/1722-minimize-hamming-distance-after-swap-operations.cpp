class Solution {
public:
    
    // DSU + Map se kiya hai 
    int findparent(int u, vector<int>&parent)
    {
        if(u == parent[u])
        return u;

        return parent[u] = findparent(parent[u], parent);
    }

    void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int Pu = findparent(u,parent);
        int Pv = findparent(v,parent);

        if(Pu == Pv)
        return;

        if(rank[Pu] > rank[Pv])
           parent[Pv] = Pu;
        else if(rank[Pv] > rank[Pu])
           parent[Pu] = Pv;
        else
        {
            rank[Pu]++;
            parent[Pv] = Pu;
        }   
    }


    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();

        vector<int>parent(n,0);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<allowedSwaps.size(); i++)
        {
            int u = allowedSwaps[i][0];
            int v = allowedSwaps[i][1];

            unionbyrank(u,v,parent,rank);
        }
               //    group              ele,freq ,kyuki agr hme same element ko 2 jagah chaiye pr hmaare paas ek hi baar hai
        unordered_map<int,unordered_map<int,int>> mp;
        
        // uss group me kon kon se element hone waale hai
        for(int i=0; i<n; i++)
        {
            int group = findparent(i,parent);
            int ele = source[i];

            mp[group][ele]++;
        }
        
        // finding answer
        int diff = 0;

        for(int i=0;i<n;i++)
        {
            int group = findparent(i,parent);
            int targt = target[i];

            if(mp[group][targt] > 0)
            {
                mp[group][targt]--;
            }
            else
            diff++;
        }

        return diff;
    }
};