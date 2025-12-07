class Solution {
public:
    
    // from last on passing n,m as for i,j
    
    // int find(int i,int j,string &str,string &t,vector<vector<int>>&dp)
    // {
    //     // Base case
    //     if(j==0)
    //     return 1;
    //     if(i==0)
    //     return 0;
        
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];

    //     // logic
    //     if(str[i-1]==t[j-1])
    //     return dp[i][j] = find(i-1,j-1,str,t,dp)+find(i-1,j,str,t,dp);
    //     else
    //     return dp[i][j] = find(i-1,j,str,t,dp);
    // }

    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m =t.size();

        vector<vector<double>>dp(n+1,vector<double>(m+1,0)); 

        // initialization
        for(int i=0;i<=n;i++)
        dp[i][0] = 1;

        // logic
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j]; // find(i-1,j-1,str,t,dp)+find(i-1,j,str,t,dp);
                else
                dp[i][j] = dp[i-1][j]; // find(i-1,j,str,t,dp);
            }
        }

        return (int)dp[n][m]; // find(n,m,s,t,dp);
    }
};