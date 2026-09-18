class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {

      // Making the adjacency matrix
      vector<vector<int>>adj(n+1,vector<int>(n+1,1e9));
      for(int i=1;i<n;i++)
      {
          adj[i][i+1]=1;
          adj[i+1][i]=1;
      }

    // adding additional given edge between x nd y house
      adj[x][y]=1;
      adj[y][x]=1;

    // Applying Floyd warshall Algorithm

      for(int k=1;k<=n;k++)
      {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    adj[i][j] = min( adj[i][j] , adj[i][k]+adj[k][j] );
                }
            }
      }
     
    //   calculating the pairs of particular distance from 1 to n
      vector<int>result(n);
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(i==j || adj[i][j] == 1e9)
              continue;

              result[adj[i][j]-1]++;
          }
      }

      return result;
        
    }
};