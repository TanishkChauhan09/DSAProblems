class Solution {
public:
    
    // Top-down/ Memoization
    vector<vector<vector<int>>> dp;

    long long findForAlice(int index, int M, vector<int>&piles, int &n, int person)
    {
        // Base condition
        if(index >=n)
          return 0;

        // optimization
        if( dp[index][M][person] != -1)
          return dp[index][M][person];


        long long result = person == 1 ? -1 : INT_MAX;  // Alice ki chance hogi toh usse maximum chahiye isliye result me -1 hona chahiye and jb bob ki chance ho toh wo mini dega uske liye result me INT_MAX hoga toh isiliye

        long long sum = 0; 
        for(int x = 1; x <= min(2*M, n-index); x++) // out of array na chla jaaye uske liye
        {
            sum += piles[x+ index-1];

            if(person) // Alice chance : do your best
            {
                long long getBest = findForAlice(index+x, max(M, x), piles, n, !person);

                result = max(result, sum + getBest);
            }
            else   // Bob chance : ye func alice ke liye hai toh alice bob se worst expect krega
            {
                 result = min( result, 0 + findForAlice(index+x, max(M,x), piles, n, !person) );
            }
        } 
        return dp[index][M][person] =  result;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        int M = 1;

        int person = 1; // Alice start krega game ko

        dp.resize(n+1, vector<vector<int>>(n+1, vector<int>(2,-1)));

        return findForAlice(0, M, piles, n, person);
        
    }
};