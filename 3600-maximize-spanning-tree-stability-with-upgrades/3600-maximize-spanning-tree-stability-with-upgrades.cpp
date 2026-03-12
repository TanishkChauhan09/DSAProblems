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
    
    // now trying to change the return type of the function
    bool find(vector<vector<int>>&edges,int stability,int n,int k)
    {
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        vector<vector<int>>canbe_used;

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            int must = edges[i][3];

            if(must==1)
            {
                if (wt < stability)
                return 0;   // required edge too weak

                // safe to add
                if(findparent(u,parent)!=findparent(v,parent))
                unionbyrank(u,v,parent,rank);
            }
            else
            {
                if(wt>=stability)
                {
                    if(findparent(u,parent)!=findparent(v,parent))
                    unionbyrank(u,v,parent,rank);
                }
                else if(2*wt>=stability)
                {
                    canbe_used.push_back({u,v,wt});
                }
            }
        }

        // USE UPGRADED EDGES (only k allowed)
        for(int i=0;i<canbe_used.size();i++)
        {
            int u = canbe_used[i][0];
            int v = canbe_used[i][1];

            if(findparent(u,parent)!=findparent(v,parent))
            {
                // it means mst still incomplete so i need to add more edge that can become of size stability or greater only if we have upgrade
                // suppose we need to add an edge but unable because we are now out of upgrades
                if(k==0)
                 return 0;

                unionbyrank(u,v,parent,rank);
                k--; 
            }
        }

        // checking  a complete mst formed or not using the values in the parent all must be of same number as everyone's will have the same ultimate parent now
        int ult_parent = findparent(0,parent);
        for(int i=1;i<n;i++)
        {
            if(ult_parent!=findparent(i,parent))
            return 0;
        }

        return 1;
        
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        
         int low=1, high=0;
         vector<int>parent(n,0);
         vector<int>rank(n,0);
         for(int i=0;i<n;i++)
         parent[i] = i;

         for(int i=0;i<edges.size();i++)
         {
            int wt = edges[i][2];
            int must = edges[i][3];

            if(must==1)
            {
                int u = edges[i][0];
                int v = edges[i][1];
                
                // one of the most important part try to undertand this and its test case is
                //  n = 3
                // edges = [[0,1,1,1],[1,2,1,1],[2,0,1,1]]
                // k = 0
                // Output
                // 1
                // Expected
                // -1

                //  AGAR edge must=1 hai pr dono ke ultimate parent same aa rha hai toh iska matlb sbki must ko lena hai aur iss se cycle bnegi hi bnegi 
                if(findparent(u,parent)==findparent(v,parent))
                return -1;
                unionbyrank(u,v,parent,rank);

                high = max(high,wt);
            }  
            else
            high = max(high,2*wt); 
         }

         int ans=-1;

         while(low<=high)
         {
            int mid = low+(high-low)/2;

            if(find(edges,mid,n,k))
            {
                ans = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
         }

         return ans;
        
    }
};