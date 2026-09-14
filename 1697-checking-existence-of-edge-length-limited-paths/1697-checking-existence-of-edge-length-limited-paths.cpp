class Solution {
public:
    
    int findparent(int u,vector<int>&parent)
    {
        if(u==parent[u])
        return u;

        return parent[u] = findparent(parent[u],parent);
    }

    void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int Pu = findparent(u,parent);
        int Pv = findparent(v,parent);

        if(Pu==Pv)
        return;

        if(rank[Pu]>rank[Pv])
        {
            parent[Pv] = Pu;
        }
        else if(rank[Pv]>rank[Pu])
        {
            parent[Pu] = Pv;
        }
        else
        {
            rank[Pu]++;
            parent[Pv] = Pu;
        }
    }


    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        vector<int>parent(n,0);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0;i<queries.size();i++)
        {
            queries[i].push_back(i);
        }

        auto comp = [&](vector<int>&v1,vector<int>&v2)
        {
            return v1[2]<v2[2];
        };

        sort(edgeList.begin(),edgeList.end(),comp);
        sort(queries.begin(),queries.end(),comp);

        int j=0;
        vector<bool>result(queries.size());

        for(int i=0;i<queries.size();i++)
        {
            int q_wt = queries[i][2];

            while(j<edgeList.size() && edgeList[j][2]<q_wt)
            {
                int graph_i = edgeList[j][0];
                int graph_j = edgeList[j][1];

                unionbyrank(graph_i,graph_j,parent,rank);
                j++;
            }

            int query_i = queries[i][0];
            int query_j = queries[i][1];
            int index = queries[i][3];

            if(findparent(query_i,parent)!=findparent(query_j,parent))
            {
                result[index]=0;
            }
            else
            {
                result[index]=1;
            }
        }
       
       return result;

    }
};