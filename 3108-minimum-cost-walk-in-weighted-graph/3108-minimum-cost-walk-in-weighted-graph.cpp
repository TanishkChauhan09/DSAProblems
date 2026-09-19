class Solution {
public:
    
    // WHEN WE DO MORE '&' THE RESULT WILL NEVER INCREASE AND POSSIBLY IT MAY GET DECREASE
    // kisi bhi no. ka -1 se '&' lene pr whi number aa jaata hai ::::   a&-1 = a

    int findparent(int u,vector<int>&parent)
    {
        if(u==parent[u])
        return u;

        return findparent(parent[u],parent);
    }

    void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int Pu = findparent(u,parent);
        int Pv = findparent(v,parent);
        
        if(Pu==Pv)
        return;

        if(rank[Pu]>rank[Pv])
        parent[Pv] = Pu;
        else if(rank[Pv]>rank[Pu])
        parent[Pu] = Pv;
        else
        {
            rank[Pu]++;
            parent[Pv] = Pu;
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {

        vector<int>parent(n,0);
        vector<int>rank(n,0);
        vector<int>result(n,-1);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            int prnt_u = findparent(u,parent);
            int prnt_v = findparent(v,parent);

            if(prnt_u != prnt_v)
            {
                unionbyrank(prnt_u,prnt_v,parent,rank);
                int newparent = findparent(prnt_u,parent);
                result[newparent] = result[prnt_u] & result[prnt_v];
                result[newparent] &= wt;
            }
            else
            {
                result[prnt_u]&=wt;
            }
        }

        vector<int>ans(query.size());

        for(int i=0;i<query.size();i++)
        {
            int u = query[i][0];
            int v = query[i][1];

            if(u==v)
            {
                ans[i]=0;
                continue;
            }

            if(findparent(u,parent)!=findparent(v,parent))
            {
                ans[i] = -1;
                continue;
            }
            else
            {
                int prnt = findparent(u,parent);
                ans[i] = result[prnt];
            }
        }
        
        return ans;
        
    }
};