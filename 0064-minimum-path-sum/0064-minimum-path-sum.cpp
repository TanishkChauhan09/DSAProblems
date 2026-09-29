class Solution {
public:

    // Front se Recursion se solve krne pr

    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        // for last row

        return find(0,0,n,m,grid,dp);

    }

    int find(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<long long>>&dp)
    {
        // Base Condition
        if(i==n-1 && j==m-1)
        return grid[i][j];
        if(i==n || j==m)
        return 1e9;

        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int down = find(i+1,j,n,m,grid,dp);
        int right = find(i,j+1,n,m,grid,dp);

        dp[i][j] = grid[i][j]+min(down,right);
        return dp[i][j];
    }


};