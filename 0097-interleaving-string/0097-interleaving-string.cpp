class Solution {
public:

//    Recursion+Top_Down(Memoization)
    
    bool find(int i,int j,int k,string &s1,string &s2,string &s3,int n,int m,vector<vector<int>>&dp)
    {
        // Base case
        if(i==n && j==m)
        {
            return k==n+m;
        }

        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(i<n && s1[i]==s3[k])
        if(find(i+1,j,k+1,s1,s2,s3,n,m,dp))
        return dp[i][j] = 1;
        
        if(j<m && s2[j]==s3[k])
        if(find(i,j+1,k+1,s1,s2,s3,n,m,dp))
        return dp[i][j] = 1;
        
        return dp[i][j] = 0;
    }
  

    bool isInterleave(string s1, string s2, string s3) {
        
        int n = s1.size();
        int m = s2.size();
        
        if(n+m!=s3.size())
        return 0;

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return find(0,0,0,s1,s2,s3,n,m,dp);
    }
};