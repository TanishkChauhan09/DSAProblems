class Solution {
public:
   
    int dfs1(int node,int parent,vector<vector<int>>&adj,int count_node,int &res,vector<int>&count)
    {
        res+=count_node;
        int tempcount=1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(neigh==parent)
              continue;

            tempcount += dfs1(neigh,node,adj,count_node+1,res,count);  
        }
        count[node] = tempcount;
        return tempcount;
    }

    void dfs2(int parent,vector<vector<int>>&adj,int prev_node,vector<int>&result,vector<int>&count,int &n)
    {
        for(int j=0;j<adj[parent].size();j++)
        {
            int child = adj[parent][j];

            if(child==prev_node)
              continue;

            result[child] = result[parent]-count[child]+(n-count[child]);
            dfs2(child,adj,parent,result,count,n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

       vector<vector<int>>adj(n);

       for(int i=0;i<edges.size();i++)
       {
           int u = edges[i][0];
           int v = edges[i][1];

           adj[u].push_back(v);
           adj[v].push_back(u);
       }

       vector<int>count(n,0);
       int res = 0;
       dfs1(0,-1,adj,0,res,count);

       vector<int>result(n,0);
       result[0] = res;
      
      dfs2(0,adj,-1,result,count,n);

      return result;
    }
};