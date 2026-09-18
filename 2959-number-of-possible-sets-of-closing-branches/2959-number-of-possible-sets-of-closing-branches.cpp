class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
         
        int result = 0;

        for(int set=0;set<pow(2,n);set++)  // pow(2,n) also (1<<n)
        {
            vector<vector<int>>adj(n,vector<int>(n,1e9));

            for(int i=0;i<roads.size();i++)
            {
                int u = roads[i][0];
                int v = roads[i][1];
                int wt = roads[i][2];
                
                // if both u and v belongs to the set or not
                if(( set >> u & 1)  && ( set >> v & 1))
                {
                    adj[u][v] = min(adj[u][v] , wt);
                    adj[v][u] = min(adj[u][v] , wt);
                }
            }

            for(int i=0;i<n;i++)
            {
                adj[i][i]=0;
            }
           
            // applying floyd warshall algo
            for(int k=0;k<n;k++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                    }
                }
            }
         
          bool flag=1;
          for(int i=0;i<n;i++)
          {
                for(int j=0;j<n;j++)
                {
                    if(i==j)
                    continue;

                    if((set >> i &1)  &&  (set >> j & 1))
                    {

                        if(adj[i][j]>maxDistance)
                        {
                            flag=0;
                            break;
                        }
                    }
                }
          }

          if(flag)
          {
            result++;
          }
            
        }

        return result;
        
    }
};