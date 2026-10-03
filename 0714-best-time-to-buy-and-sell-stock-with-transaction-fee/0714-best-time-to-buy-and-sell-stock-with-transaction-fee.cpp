class Solution {
public:
    
    // Top- down / Memoization
    //  hrr ek complete transacton pr kuch fees/charge/ apni side se dene pdenge toh jb sell kiya tb iss txnfees ko subtract krdenge

    vector<vector<int>>dp;
    
    int find(int index, vector<int>&prices, int canbuy, int &n, int txnfee)
    {
        if(index >= n)
         return 0;

        // optimization by top-down
        if(dp[index][canbuy] != -1 )
           return dp[index][canbuy];

        if(canbuy)
        {
            int buy = -prices[index] + find(index+1, prices, !canbuy, n, txnfee);
            int notBuy = 0 + find(index+1, prices, canbuy, n, txnfee);

            return dp[index][canbuy]  =  max( buy, notBuy);
        } 
        else
        {
            int sell = prices[index]- txnfee + find(index+1, prices, !canbuy, n, txnfee);
            int notSell = 0 + find(index+1, prices, canbuy, n, txnfee);

            return dp[index][canbuy]  =  max(sell, notSell); 
        }

    }

    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();

        dp.resize(n+1, vector<int>(2, -1)); // memoization

        return find(0, prices, 1, n, fee);
    }
};