class Solution {
public:
    
    // jb bhi hmm kisi 'n' ka ans nikaal rhe hai titling krne me toh intermediate wale ka nhi bnn na chahiye isko bhi dhyaan me rkhna hai

    // Recursion

    // Memoization
    vector<int>dp;
     
    int mod = 1e9 + 7; 

    // int find(int n)
    // {
    //     // Base condition
    //     if( n == 1 || n == 2)
    //      return n;

    //     if(n == 3)
    //      return 5;

    //     if( dp[n] != -1)
    //       return dp[n]; 

    //     return  dp[n] = ( 2*find(n-1) % mod + find(n-3) % mod ) % mod;  
    // }

    int numTilings(int n) {

        dp.resize(n+1 , 0);

        if( n==1 || n==2 )
          return n;
        if(n==3)
          return 5;  

        dp[1] = 1, dp[2] = 2, dp[3] = 5;

        for(int i=4; i <= n; i++)
        {
            dp[i] = ( 2*dp[i-1] % mod + dp[i-3] % mod) % mod;
        }

        // return find(n);
        return dp[n];
        
    }
};