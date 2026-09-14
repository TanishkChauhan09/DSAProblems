class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int>q;
        vector<vector<int>>arr(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            if(!indegree[i])
            {
                q.push(i);
                arr[i][colors[i]-'a']=1;
            }
        }

        int ans=0;
        int count_totalNodes = 0;

       while(!q.empty())
       {
           int node = q.front();
           q.pop();

           count_totalNodes++;

           ans = max(ans,arr[node][colors[node]-'a']);

           for(int j=0;j<adj[node].size();j++)
           {
               int neigh = adj[node][j];
               indegree[neigh]--;

               for(int i=0;i<26;i++)  // i -> colors in 2D arr
               {
                   arr[neigh][i] = max(arr[neigh][i] , arr[node][i] + (colors[neigh]-'a' == i) );
               }

               if(indegree[neigh]==0)
               {
                  q.push(neigh);
               }
               
           }
       }

       if(count_totalNodes<n)
       return -1;

       return ans;

    }
};