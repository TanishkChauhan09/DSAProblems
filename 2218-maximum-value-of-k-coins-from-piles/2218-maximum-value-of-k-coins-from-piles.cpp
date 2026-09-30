class Solution {
public:

    
    // TABULATION / BOTTOM-UP  / MORE SPACE OPTIMIZATION


    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        // dp.resize( piles.size()+1 , vector<int>(k+1, 0));

        int n = piles.size();

        vector<int>dp1(k+1 , 0);  // dp[index] = dp1
        vector<int>dp2(k+1 , 0);  // dp[index+1] = dp2

        // Tabulation
         
        for(int index=n-1; index>=0; index--)
        {
            for(int t=k; t>0; t--)
            {
                // not taken
                int notTaken = dp2[t];    // k same as t   // find(index+1, piles, k);

                // taken 
                int sum = 0, maxAns = 0;

                for(int j=0; j< min(t , (int) piles[index].size() ) ; j++)
                {
                    sum += piles[index][j]; // piles ke top se continuos hi toh le skta hoon

                    int maxPoss = sum + dp2[t -(j+1)];     // find(index+1, piles, k -(j+1)) ;  

                    maxAns = max( maxAns, maxPoss);
                }
                
                dp1[t]  =  max( notTaken, maxAns);
            }

            dp2 = dp1;
        }

        // return find(0, piles, k);

        return dp1[k];
        
    }
};