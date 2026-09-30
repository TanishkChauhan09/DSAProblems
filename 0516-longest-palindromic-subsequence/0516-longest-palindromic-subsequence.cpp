class Solution {
public:

    // Recursion and Top-down

    // Memoization
    vector<vector<int>> dp;

    int LCS(int i, int j,int n, string &s1, string &s2)
    {
        if( i >= n || j >= n)
           return 0;

        // OPTIMIZATION
        if( dp[i][j] != -1 )
           return dp[i][j];   

        if(s1[i] == s2[j])
          return  dp[i][j]  =  1 + LCS(i+1, j+1, n, s1, s2);

        else
        {
            int poss1 = LCS(i, j+1, n, s1, s2);
            int poss2 = LCS(i+1, j, n, s1, s2);

            return dp[i][j]  =  max(poss1, poss2);
        }     
    }
    int longestPalindromeSubseq(string s) {

        int n = s.size();

        dp.resize(n+1, vector<int>(n+1, -1));

        string s2 = s;

        reverse(s2.begin(), s2.end());
        
        return LCS(0, 0, n, s,s2);
    }
};