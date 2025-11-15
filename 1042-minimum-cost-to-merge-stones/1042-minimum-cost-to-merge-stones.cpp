class Solution {
public:

    
    int find(int i,int j,int k,vector<int>&prefix_sum,vector<vector<int>>&dp)
    {
        // Base case
        if(i>=j) return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int ans = INT_MAX;
        for(int partition=i;partition<j;partition+=(k-1))
        {
            // left part is returning the min sum of 'k' consecutive numbers i am not saying that 
            int l = find(i,partition,k,prefix_sum,dp);
            // right part is returning the min sum of 'k' consecutive numbers
            int r = find(partition+1,j,k,prefix_sum,dp);
            // and then adding the both left and right to make it a single value and then goes to next patition and storing the mini for each partition and then finally returning
            
            ans = min(ans,l+r);
        }
        
        if((j-i)%(k-1)==0)
        {
            ans+=prefix_sum[j+1]-prefix_sum[i];
        }
        
        
        return dp[i][j] = ans;
    }

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
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int i=0;
        return find(i,n-1,k,prefix_sum,dp);
    }
};