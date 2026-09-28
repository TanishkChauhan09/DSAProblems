class Solution {
public:
    
    // bottom up
    

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int minAns = INT_MAX;

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i=0; i<n; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int min1 = INT_MAX, min3 = INT_MAX;
                // i-1 is going to valid always, kyuki 1 se start kr rha hoon
                if(j-1 >= 0)
                   min1 = dp[i-1][j-1];  

                int min2 = dp[i-1][j]; // always valid no need any condition
                
                if(j+1 < n)
                    min3 = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min({ min1, min2, min3 });
            }
        }

        for(int i=0;i<n;i++)
        {
            minAns = min(minAns , dp[n-1][i]);
        }

        return minAns;
        
    }
};