class Solution {
public:
     
       // simply dfs use kiya hai bss hrr node tk ek count lekr chal rhe hai jisko hmne ek temp vector me store kr liya hai
    
       int ans=-1;

       void dfs(int node,vector<vector<int>>&edge,vector<int>&visited,vector<int>&path,vector<int>&temp)                                                                                   
       {
           visited[node]=1;
           path[node]=1;
           
           for(int i=0;i<edge[node].size();i++)
           {
               int neighbour = edge[node][i];
               
               if(!visited[neighbour])
               {
                   temp[neighbour] = temp[node]+1;
                   dfs(neighbour,edge,visited,path,temp);
               }
               else
               {
                   if(path[neighbour])
                   {
                       ans = max(ans,temp[node]-temp[neighbour]+1);                            
                   }
               }
              
           }
           path[node] = 0;
       }

    int longestCycle(vector<int>& edges) {
        
        int n = edges.size();
        vector<int>visited(n,0),path(n,0),temp(n,1);
        
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++)
        {
            if(edges[i]!=-1)
            {
                int u = i;
                int v = edges[i];
                adj[u].push_back(v);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,path,temp);
            }
        
        }
        
        return ans;
    }
};