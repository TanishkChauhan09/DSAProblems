class Solution {
public:
   
    // Floyd warshall algorithm se sbhi nodes se sbhi nodes tk ki minimum distance nikaal li hai

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>adj(n,vector<int>(n,1e9));

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u][v] = wt;
            adj[v][u] = wt;
        }
        
        // floyd warshall algorithm me iska bhut satarkta se dhyaan rkhna hai
        // ke hrr ek node ki khud se khud tk ki distance ko 0 jrur bnana hai
        for(int i=0;i<n;i++)
        {
            adj[i][i] = 0;
        }
         
        // Applying floyd warshall 
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    adj[i][j] = min(adj[i][j] , adj[i][k]+adj[k][j]);
                }
            }
        }
        
        int ans = INT_MAX;
        int result;
        
        // finding the maximum index with minimum count of cities with dstance atmost distanceThreshold
        for(int i=0;i<n;i++)
        {
            int count=0;

            for(int j=0;j<n;j++)
            {
                if(adj[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }

            if(count<=ans)
            {
                result = i;
                ans = count;
            }
        }

        return result;

    }
};