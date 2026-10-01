class Solution {
public:
    
    // bottom-up/ tabulation
    vector<vector<int>>dp;
    
    // LCS nikaal lenge and then total string size me se LCS ko subtract krdenge whi  hoga minimum insetion to make palindromin string kyuki jo palindrome uss string me phle se present hai uske alawa hi toh characters add krne pdenge

    int minInsertions(string s) {

        int n = s.size();

        dp.resize(n+1, vector<int>(n+1, 0));

        string s2 = s;
        reverse( s2.begin(), s2.end());

        // tabulation

        for(int i=n-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(s[i] == s2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }

                else
                {
                    int keep_i =  dp[i][j+1];
                    int keep_j =  dp[i+1][j];

                    dp[i][j] = max( keep_i, keep_j); 
                }
            }
        }

        int size = dp[0][0]; 
        
        return n - size;
    }
};