class Solution {
public:
    
    // Bottom-up (Tabulation)

    int mergeStones(vector<int>& stones, int k) {
        
         int n = stones.size();
        
        // agar k consecutive ka sum possible hi nhi hua tb
        if((n-1)%(k-1)!=0)
        return -1;
        
        vector<int>prefix_sum(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            prefix_sum[i+1] = prefix_sum[i]+stones[i];
        }
        
        // Memoization
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        // logic
        // in T.M: i=0 to i=j tk max and j=n-1
        //         j=n-1 to j=i tk max
        
        // in B.T: i=n-1 to i=0 tk max
        //         j=i+1 to j=n-1 tk max
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<=n-1;j++)
            {
                int ans = INT_MAX;
                
                for(int partition=i;partition<j;partition+=(k-1))
                {

                    int l = dp[i][partition]; //find(i,partition,k,prefix_sum,dp);
                    
                    int r = dp[partition+1][j]; // find(partition+1,j,k,prefix_sum,dp);
                    
                    ans = min(ans,l+r);
                }
                
                if((j-i)%(k-1)==0)
                {
                    ans+=prefix_sum[j+1]-prefix_sum[i];
                }
                
                
                dp[i][j] = ans;
            }
        }
        
        // int i=0;
        // return find(i,n-1,k,prefix_sum,dp);
        return dp[0][n-1];  // loop me jha pr i and j end ho rhe hai usi ko dekhkr final dp me se row,col return krna hai
    }
};