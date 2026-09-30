class Solution {
public:

    
    // TABULATION / BOTTOM-UP


    // Recursion and Top-down 

    // Memoization
    vector<vector<int>> dp;

    // int find( int index, vector<vector<int>>&piles, int k)
    // {
    //     if(index >= piles.size() || k <= 0)
    //       return 0;

    //     if(dp[index][k] != -1)
    //       return dp[index][k];  

    //     int notTaken = find(index+1, piles, k);

    //     // taken at thetop of pile
    //     int sum = 0, maxAns = 0;

    //     for(int j=0; j< min(k , (int) piles[index].size() ) ; j++)
    //     {
    //         sum += piles[index][j]; // piles ke top se continuos hi toh le skta hoon

    //         int maxPoss = sum + find(index+1, piles, k-(j+1)) ;   // remaining jo coins bchenge wo dhyaan se calculate krna hai agr jth index tk kisi ek pile ke top se coins leliye toh ab  " total-(j+1) " hi bche honge

    //         maxAns = max( maxAns, maxPoss);
    //     }  

    //     return  dp[index][k]  =  max( notTaken, maxAns);
    // }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        dp.resize( piles.size()+1 , vector<int>(k+1, 0));

        // Tabulation
        int n = piles.size();
         
        for(int index=n-1; index>=0; index--)
        {
            for(int t=k; t>0; t--)
            {
                // not taken
                int notTaken = dp[index+1][t];    // k same as t   // find(index+1, piles, k);

                // taken 
                int sum = 0, maxAns = 0;

                for(int j=0; j< min(t , (int) piles[index].size() ) ; j++)
                {
                    sum += piles[index][j]; // piles ke top se continuos hi toh le skta hoon

                    int maxPoss = sum + dp[index+1][t -(j+1)];     // find(index+1, piles, k -(j+1)) ;  

                    maxAns = max( maxAns, maxPoss);
                }
                
                dp[index][t]  =  max( notTaken, maxAns);

            }
        }

        // return find(0, piles, k);

        return dp[0][k];
        
    }
};