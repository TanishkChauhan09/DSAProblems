class Solution {
public:
    
    int findparent(int node,vector<int>&parent)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node] = findparent(parent[node],parent);
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
            parent[Pu] = Pv;
            rank[Pv]++;
        }
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        int total_node = vals.size();

        map<int,vector<int>>mp2;

        for(int i=0;i<total_node;i++)
        {
            int val = vals[i];
            mp2[val].push_back(i);
        }

        vector<int>parent(vals.size());
        vector<int>rank(vals.size(),0);

        for(int i=0;i<parent.size();i++)
        {
            parent[i] = i;
        }
        
        int result = total_node;

        vector<int>isactive(total_node,0);

        for(auto &it:mp2)
        {
            vector<int>temp = it.second;
            for(int i:temp)
            {
                for(int j:mp[i])
                {
                    if(isactive[j])
                    {
                        unionbyrank(i,j,parent,rank);
                    }
                }

                isactive[i] = 1;

            }

            vector<int>currvaluenodesparent;
            for(int i:temp)
            {
                int ithultimateparent = findparent(i,parent);
                currvaluenodesparent.push_back(ithultimateparent);
            }
            
            sort(currvaluenodesparent.begin(),currvaluenodesparent.end());

            int t = currvaluenodesparent.size();

            for(int i=0;i<t;i++)                                             
            {
               long long count=0;

               int curr_parent = currvaluenodesparent[i];

               while(i<t && currvaluenodesparent[i]==curr_parent)
               {
                count++;
                i++;
               }

               i--;

               int formula = count*(count-1)/2;
               result+=formula;

            }
        }
        
        return result;
    }
};