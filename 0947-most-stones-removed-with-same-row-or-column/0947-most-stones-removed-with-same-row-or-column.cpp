class Solution {
public:
    
    int findparent(int u,vector<int>&parent)
    {
        if(u==parent[u])
        return parent[u];

        // path  compression
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

    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        vector<int>parent(n,0);
        vector<int>rank(n,0);

        // initially everyone will be their own parent or belong to different sets
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                unionbyrank(i,j,parent,rank);
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            count++;
        }

        return n-count;
    }
};