class Solution {
public:
    
    // BOTTOM UP/ TABULATION

    // Recursion and Top-down

    // Memoization
    vector<vector<int>> dp;

    // int LCS(int i, int j,int n, string &s1, string &s2)
    // {
    //     if( i >= n || j >= n)
    //        return 0;

    //     // OPTIMIZATION
    //     if( dp[i][j] != -1 )
    //        return dp[i][j];   

    //     if(s1[i] == s2[j])
    //       return  dp[i][j]  =  1 + LCS(i+1, j+1, n, s1, s2);

    //     else
    //     {
    //         int poss1 = LCS(i, j+1, n, s1, s2);
    //         int poss2 = LCS(i+1, j, n, s1, s2);

    //         return dp[i][j]  =  max(poss1, poss2);
    //     }     
    // }


    int longestPalindromeSubseq(string s) {

        int n = s.size();

        dp.resize(n+1, vector<int>(n+1, 0));

        string s2 = s;

        reverse(s2.begin(), s2.end());

        // Tabulation

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = n-1; j >=0; j--)
            {
                if(s[i] == s2[j])
                  dp[i][j]  =  1 + dp[i+1][j+1];   // LCS(i+1, j+1, n, s1, s2);

                else
                {
                    int poss1 = dp[i][j+1];        // LCS(i, j+1, n, s1, s2);
                    int poss2 = dp[i+1][j];        // LCS(i+1, j, n, s1, s2);

                    dp[i][j]  =  max(poss1, poss2);
                }  
            }
        }
        
        // return LCS(0, 0, n, s,s2);
        return dp[0][0];
    }
};