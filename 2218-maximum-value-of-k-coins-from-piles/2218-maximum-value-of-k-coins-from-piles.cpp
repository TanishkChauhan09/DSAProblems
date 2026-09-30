class Solution {
public:

// Error ka main reason min() ke dono arguments ka type different hona hai.

// Tumhare code mein:

// min(k, piles[index].size())

// k most probably int hai, jabki:

// piles[index].size()

// ka type size_t / unsigned long hota hai.

// Isliye C++ decide nahi kar paa raha ki kaunsa min() use kare.

// Simple fix  : - min(k, (int)piles[index].size())




    
    // Recursion and Top-down 

    // Memoization
    vector<vector<int>> dp;

    int find( int index, vector<vector<int>>&piles, int k)
    {
        if(index >= piles.size() || k <= 0)
          return 0;

        if(dp[index][k] != -1)
          return dp[index][k];  

        int notTaken = find(index+1, piles, k);

        // taken at thetop of pile
        int sum = 0, maxAns = 0;

        for(int j=0; j< min(k , (int) piles[index].size() ) ; j++)
        {
            sum += piles[index][j]; // piles ke top se continuos hi toh le skta hoon

            int maxPoss = sum + find(index+1, piles, k-(j+1)) ;   // remaining jo coins bchenge wo dhyaan se calculate krna hai agr jth index tk kisi ek pile ke top se coins leliye toh ab  " total-(j+1) " hi bche honge

            maxAns = max( maxAns, maxPoss);
        }  

        return  dp[index][k]  =  max( notTaken, maxAns);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {

        dp.resize( piles.size()+1 , vector<int>(k+1, -1));

        return find(0, piles, k);
        
    }
};