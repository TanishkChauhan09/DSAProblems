class Solution {
public:

    int res = 0;

    int dfs(int node,int parent,vector<vector<int>>&adj,string &str)
    {
        int largest=0;
        int sec_largest=0;

        // visiting all neighbours to get the largest and second largest from all the neighbours because path is made with only two edges
        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(neigh==parent)
              continue;
 
            int child_cost = dfs(neigh,node,adj,str);

            if(str[neigh]==str[node])
              continue; 

            if(child_cost>sec_largest)
            {
                sec_largest = child_cost;
            }
            if(largest<sec_largest)
            {
                swap(largest,sec_largest);
            }
        }

        // after getting the largest and sec_largest from all the neighbours we have some cases
        int case1 = 1+largest+sec_largest;
        int case2 = 1+max(largest,sec_largest);

        res = max({res,case1,case2});

        return case2;
    }

    int longestPath(vector<int>& parent, string s) {
      
     int n = parent.size();
     vector<vector<int>>adj(n);

     for(int i=1;i<parent.size();i++)
     {
        int u = i;
        int v = parent[i];

        adj[u].push_back(v);
        adj[v].push_back(u);
     }

     dfs(0,-1,adj,s);

     return res;
        
    }
};