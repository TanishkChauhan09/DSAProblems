class Solution {
public:

    typedef long long LL;
    
    // Memoization
    vector<int> dp;
    
    int find(int n)
    {
        if(n==0) 
          return 0;

        if(dp[n] != -1)
          return dp[n];  

        int ans = INT_MAX;  

        for(int i=1; LL(i*i) <= n; i++)  // <= n likhna yaad rkhna hai
        {
            int minRes = find( n - LL(i*i));

            if(minRes != INT_MAX)
              ans= min(ans, 1 + minRes );
        }  
        return dp[n] = ans;
    }

    int numSquares(int n) {
        
        dp.resize(n+1,-1);
        return find(n);
        
    }
};