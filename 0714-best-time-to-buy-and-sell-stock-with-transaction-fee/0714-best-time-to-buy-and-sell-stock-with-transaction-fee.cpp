class Solution {
public:
    
    // bottom-up / tabulation

    //  hrr ek complete transacton pr kuch fees/charge/ apni side se dene pdenge toh jb sell kiya tb iss txnfees ko subtract krdenge

    vector<vector<int>>dp;

    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();

        dp.resize(n+1, vector<int>(2, 0)); // initialization

        // tabulation
        for(int index=n-1; index>=0; index--)
        {
            for(int canbuy=1; canbuy>=0; canbuy--)
            {
                if(canbuy)
                {
                    int buy = -prices[index] + dp[index+1][!canbuy];
                    int notBuy = 0 + dp[index+1][canbuy];

                    dp[index][canbuy]  =  max( buy, notBuy);
                } 
                else
                {
                    int sell = prices[index]- fee + dp[index+1][!canbuy]; // fee ko sell krne ke baad subtract krna hai
                    int notSell = 0 + dp[index+1][canbuy];

                    dp[index][canbuy]  =  max(sell, notSell); 
                }

            }
        }

        // return find(0, prices, 1, n, fee);
        return dp[0][1];
    }
};