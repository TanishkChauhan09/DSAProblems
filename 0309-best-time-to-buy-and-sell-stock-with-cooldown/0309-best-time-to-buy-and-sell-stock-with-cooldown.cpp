class Solution {
public:
    
    // Recursion  Top-down

    // Memoization
    vector<vector<int>> dp;

    int find(int index, int TxnType, vector<int>&prices, int &n)
    {
        if(index >= n)
          return 0;

        if(dp[index][TxnType] != -1)
          return dp[index][TxnType];  

        int maxProfit = 0;  

        if(TxnType) // buy
        {
            int buy = -prices[index] + find(index+1, 0, prices, n);  // buy krne ke baad sell krunga
            int notbuy = 0 + find( index+1, 1, prices, n);  // still buy kr skta hoon isliye 1 hi rhne diya maine
        
            maxProfit = max( buy , notbuy);
        }  

        else
        {
            int sell = prices[index] + find(index+2 , 1, prices, n); // sell krdiya pr cooldown ki wajah se ek din ka gap lena pdega isiliye index+2 kiya and sell krdiya toh ab buy krunga isiliye TxnType=0 krdiya
            int notsell = 0 + find(index+1, 0, prices, n);   // still sell krskta hoon

            maxProfit = max( sell , notsell);
        }

        return dp[index][TxnType] = maxProfit;
    }
    
    int maxProfit(vector<int>& prices) {
        
        int buy = 1;
        int n = prices.size();

        dp = vector<vector<int>>(n+1 , vector<int>(2,-1));
        
        return find(0 , buy ,prices, n);
    }
};