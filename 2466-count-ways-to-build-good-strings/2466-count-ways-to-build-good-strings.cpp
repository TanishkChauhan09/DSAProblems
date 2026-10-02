class Solution {
public:
    
    // Bottom-up/ Tabulation
    vector<int>dp;
    int mod = 1e9 + 7;
    
    int countGoodStrings(int low, int high, int zero, int one) {

        dp.resize(high+3 , 0);

        // tabulation
        for(int len = high; len >= 0 ; len--) // len ko 0 se high ke equal tk jaa rhe the isiliye 
        {
            int ans = 0; 

            int temp1 = len + zero;

            if(temp1 <= high)
            {
                int p1 =  dp[temp1];          // find(temp1, low, high, zerocnt, onecnt);

                if( low <= temp1 && temp1 <= high) 
                {
                    ans = (1 + p1 ) %mod;
                }
                else
                ans = p1 %mod;
            }

            int temp2 = len + one;

            if(temp2 <= high)  // dp overflow index tk bnaayi hi nhi isiliye
            {
                int p2 = dp[temp2];        // find(temp2, low, high, zerocnt, onecnt);

                if( low <= temp2 &&  temp2 <= high) 
                {
                    ans = (ans + 1 + p2 )%mod;
                }
                else
                ans = (ans + p2) %mod; 
            } 

            dp[len] = ans %mod;  
        }
        
        // return find(0, low, high, zero, one) %mod;
         return dp[0];
    }
};