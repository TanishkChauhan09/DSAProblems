class Solution {
public:

    // as we have said that the cycle is not given in this, so we do not need to worry to take a visited array , but yes from where we have come we did not want to go again on that so for that we should be keep a track for the parent , when neighbour sees its parent ,if ignores that by continue

    int dfs(int curr_node,int parent,vector<vector<int>>&adj,vector<bool>&hasApple)
    {      
          int timer = 0;

          for(int j=0;j<adj[curr_node].size();j++)
          {
              if(adj[curr_node][j]==parent)
              continue;

              int getapple = dfs(adj[curr_node][j],curr_node,adj,hasApple);

              if(getapple>0 || hasApple[adj[curr_node][j]] )
              {
                timer += 2+getapple;
              }
          } 

          return timer;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       
       int V = hasApple.size();

       vector<vector<int>>adj(V);
       for(int i=0;i<edges.size();i++)
       {
           int u = edges[i][0];
           int v = edges[i][1];

           adj[u].push_back(v);
           adj[v].push_back(u);
       }
     
      int ans = dfs(0,-1,adj,hasApple);
      return ans;

    }
};