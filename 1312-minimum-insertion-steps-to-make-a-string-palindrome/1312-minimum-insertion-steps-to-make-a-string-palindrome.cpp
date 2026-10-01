class Solution {
public:
    
    // top-down
    vector<vector<int>>dp;
    
    // LCS nikaal lenge and then total string size me se LCS ko subtract krdenge whi  hoga minimum insetion to make palindromin string kyuki jo palindrome uss string me phle se present hai uske alawa hi toh characters add krne pdenge

    int N;

    int LCS(int i, int j, string &s1, string &s2)
    {
        // Base condition
        if( i >= N || j>= N)
         return 0;

        if(dp[i][j] != -1)
          return dp[i][j]; 

        if(s1[i] == s2[j])
        return 1 + LCS(i+1, j+1, s1, s2);

        int keep_i = LCS(i, j+1, s1, s2);
        int keep_j = LCS(i+1, j, s1, s2);

        return  dp[i][j] = max( keep_i, keep_j); 
    }

    int minInsertions(string s) {

        int n = s.size();
        N = n;

        dp.resize(n+1, vector<int>(n+1, -1));

        string s2 = s;
        reverse( s2.begin(), s2.end());

        int size = LCS( 0, 0, s, s2);
        
        return n - size;
    }
};