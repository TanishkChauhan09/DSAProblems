class Solution {
public:
    
    // BOTTOM UP / TABULATION
    
    // Recursion  Top-down

    // Memoization
    vector<vector<int>> dp;

    // int find(int index, int TxnType, vector<int>&prices, int &n)
    // {
    //     if(index >= n)
    //       return 0;

    //     if(dp[index][TxnType] != -1)
    //       return dp[index][TxnType];  

    //     int maxProfit = 0;  

    //     if(TxnType) // buy
    //     {
    //         int buy = -prices[index] + find(index+1, 0, prices, n);  // buy krne ke baad sell krunga
    //         int notbuy = 0 + find( index+1, 1, prices, n);  // still buy kr skta hoon isliye 1 hi rhne diya maine
        
    //         maxProfit = max( buy , notbuy);
    //     }  

    //     else
    //     {
    //         int sell = prices[index] + find(index+2 , 1, prices, n); // sell krdiya pr cooldown ki wajah se ek din ka gap lena pdega isiliye index+2 kiya and sell krdiya toh ab buy krunga isiliye TxnType=0 krdiya
    //         int notsell = 0 + find(index+1, 0, prices, n);   // still sell krskta hoon

    //         maxProfit = max( sell , notsell);
    //     }

    //     return dp[index][TxnType] = maxProfit;
    // }
    
    int maxProfit(vector<int>& prices) {
        
        int buy = 1;
        int n = prices.size();

        dp = vector<vector<int>>(n+5 , vector<int>(2,0)); // base condition -> initialisaton

        for(int index=n-1; index>=0; index--)
        {
            for(int txnType = 0; txnType < 2; txnType++)
            {
                int maxProfit = 0;  

                if(txnType) // buy
                {
                    int buy = -prices[index] + dp[index+1][0]; 
                    int notbuy = 0 + dp[index+1][1];   
                
                    maxProfit = max( buy , notbuy);
                }  

                else  // sell
                {
                    int sell = prices[index] +  dp[index+2][1]; 
                    int notsell = 0 + dp[index+1][0];    

                    maxProfit = max( sell , notsell);
                }

                dp[index][txnType] = maxProfit;
            }
        }
        
        // return find(0 , buy ,prices, n);
        return dp[0][1];
    }
};