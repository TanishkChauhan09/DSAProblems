class Solution {
public:
    
    // bottom up/ tabulation

    // idea :isme hmne ye kiya hai ke kisi ek length ki road ko phle hmm ya toh pole1 me add krdenge ya fir pole2 me add krdenge ya fir kisi me bhi add nhi krenge taaki age aage maximum length ki pole bne toh wo unbalance na krde usko

    vector<vector<int>> dp;

    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();

        dp.resize(n+1, vector<int>(10001, INT_MIN));

        dp[n][5000] = 0;  // initialization

        // TABULATION
        
        for(int index = n-1; index >= 0; index--)
        {
            for(int diff = -5000; diff <= 5000; diff++)
            {
                int addNothing = dp[index+1][diff+5000];

                int addp1 = INT_MIN;
                int addp2 = INT_MIN;

                if(diff + rods[index] <= 5000)
                {
                    addp1 = rods[index] + dp[index+1][diff + rods[index] + 5000];
                }

                if(diff - rods[index] >= -5000)
                {
                    addp2 = rods[index] + dp[index+1][diff - rods[index] + 5000];
                }

                dp[index][diff+5000] = max({addNothing, addp1, addp2});
            }
        }

        return dp[0][5000] / 2;
    }
};