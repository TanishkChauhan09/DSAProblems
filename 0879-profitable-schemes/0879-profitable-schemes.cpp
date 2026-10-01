class Solution {
public:
    
    // Recursion and Top-down

    // Memoization
     vector<vector<vector<int>>>dp;

    int m;
    int TotalPeople;
    int ThresholdProfit;

    int mod = 1e9 +7;

    int find(int index, vector<int>&group, vector<int>&profit, int getProfit, int people)
    {
        // Base condition
        if(people > TotalPeople)
          return 0;

        if(index == m)
        {
            if( getProfit >= ThresholdProfit)
                return 1;
            
            return 0;  
              
        }  

        // optimization

        if( dp[index][getProfit][people] != -1)
          return dp[index][getProfit][people];

        int take = find(index+1, group, profit, min(ThresholdProfit, getProfit + profit[index]), people + group[index])  % mod ;

        int notTake = find(index+1, group, profit, getProfit, people) % mod ;

        return  dp[index][getProfit][people]  =   ( take + notTake ) %mod;
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        m = group.size();
        TotalPeople = n;
        ThresholdProfit = minProfit;

        dp.resize(m+1, vector<vector<int>>(minProfit+1 , vector<int>(TotalPeople+1, -1 )));

        return find(0, group, profit, 0, 0) %mod;
    }
};