class Solution {
public:
    
    // Recursion

    // idea :isme hmne ye kiya hai ke kisi ek length ki road ko phle hmm ya toh pole1 me add krdenge ya fir pole2 me add krdenge ya fir kisi me bhi add nhi krenge taaki age aage maximum length ki pole bne toh wo unbalance na krde usko
    

    // mle de rha tha toh ab uske liye hmm diff ka concept laayenge isko video se dekhna hai

    vector<vector<int>> dp;

    int find(int index, vector<int>& rods, int &n, int diff)
    {
        // Base condition
        if(index >= n)
        {
            if(diff == 0)
              return 0;

            return INT_MIN;  
        }

        if(dp[index][diff+5000] != -1)
          return dp[index][diff+5000];


        int addNothing = find(index+1, rods, n, diff);

        int addp1 = rods[index] +  find(index+1, rods, n, diff + rods[index]);

        int addp2 = rods[index]  + find(index+1, rods, n, diff - rods[index]);

        return dp[index][diff+5000]  =  max( {addNothing, addp1, addp2});
    }

    int tallestBillboard(vector<int>& rods) {
        
        int n = rods.size();

        dp.resize(n+1, vector<int>(100003, -1));  // diff negativeme jaa skta tha isiliye usko positive me laane ke liye iss size ki dp li hai

        return find(0, rods, n, 0)/2;
    }
};