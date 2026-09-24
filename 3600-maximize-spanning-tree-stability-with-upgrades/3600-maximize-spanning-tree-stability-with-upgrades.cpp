class Solution {
public:
    
    int findparent(int u, vector<int>&parent)
    {
        if(u == parent[u])
         return u;

        return parent[u] = findparent(parent[u], parent); 
    }

    void unionbyrank(int u, int v, vector<int>&parent, vector<int>&rank)
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

    int possible(int n,vector<vector<int>>&edges,int &mid, int k)
    {
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        vector<pair<int,int>>neededUpgrade;

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            int type = edges[i][3];

            if(type==1)  // must=1
            {
                if(wt<mid)
                  return 0;

                unionbyrank(u,v,parent,rank);  
            }
            else         // must=0
            {
                if(wt >= mid)
                {
                    unionbyrank(u,v,parent,rank);
                }
                else if(2*wt >= mid)
                {
                    neededUpgrade.push_back({u,v});
                }
            }
        }

        for(int i=0; i<neededUpgrade.size();i++)
        {
            int u = neededUpgrade[i].first;
            int v = neededUpgrade[i].second;

            if(findparent(u,parent) != findparent(v,parent))
            {
                if(k<=0)
                 return 0;
                unionbyrank(u,v,parent,rank);
                k--; 
            }
        }

        int ultprnt = findparent(0,parent);

        for(int i=1;i<n;i++)
        {
            if( findparent(i,parent) != ultprnt )
              return 0;
        }

        return 1;
    }

   
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
        int start = 0, end=0;
        vector<int>parent(n,0);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0; i<edges.size(); i++)
        {
             int u = edges[i][0];
             int v = edges[i][1];
             int wt = edges[i][2];
             int type = edges[i][3];

             if(type==1)
             {
                if(findparent(u,parent) == findparent(v,parent))
                  return -1;

                unionbyrank(u,v,parent,rank);  
                end = max(end,wt);
             }
             else
             {
                end = max(end, 2*wt);
             }
        }

        int ans = -1;

        while(start <= end)
        {
            int mid = start+(end-start)/2;

            if(possible(n,edges,mid,k))
            {
                ans = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }

        return ans;
       
    }
};