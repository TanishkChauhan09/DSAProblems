class Solution {
public:
    
    // Bottom-up / Tabulation
    vector<vector<vector<long long>>> dp;

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        int M = 1;

        int person = 1; // Alice start krega game ko

        dp.resize(n+1, vector<vector<long long>>(n+1, vector<long long>(2,0)));

        // tabulation

        for(int index = n-1; index>=0 ;index--)
        {
            for(int M = n; M >= 1; M--)
            {
                for(int person=1; person>=0; person--)
                {
                    long long result = person == 1 ? -1 : LLONG_MAX;  

                    long long sum = 0; 
                    for(int x = 1; x <= min(2*M, n-index); x++) 
                    {
                        sum += piles[x+ index-1];

                        if(person) 
                        {
                            long long getBest = dp[index+x][max(M,x)][!person];

                            result = max(result, sum + getBest);
                        }
                        else  
                        {
                            result = min( result, 0 + dp[index+x][max(M,x)][!person] ); 
                        }
                    } 
                     
                    dp[index][M][person] =  result;
                }
            }
        }

        // return findForAlice(0, M, piles, n, person);

        return dp[0][1][1]; // initially M=1 tha
        
    }
};