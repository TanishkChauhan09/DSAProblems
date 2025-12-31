class Solution {
public:
    
    int ROW;
    int COL;

    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};

    bool dfs(int i,int j,vector<vector<int>>&dp)
    {  
        if(i<0 || i>=ROW ||j<0 ||j>=COL ||dp[i][j]==1)
        return false; 

        if(i==ROW-1)
        return true;

        dp[i][j]=1;

        for(int k=0;k<4;k++)
        {
             int new_i = i+row[k];
             int new_j = j+col[k];

            if(dfs(new_i,new_j,dp))    
            return true;
        }

        return false;

    }

    int checkpass(int mid , vector<vector<int>>&cells)
    {
        vector<vector<int>>dp(ROW,vector<int>(COL,0));

        for(int i=0;i<=mid;i++)
        {
            int row = cells[i][0]-1;
            int col = cells[i][1]-1;

            dp[row][col]=1;
         }

         for(int j=0;j<COL;j++)
         {
            if(dp[0][j]==0 && dfs(0,j,dp))  
            return 1;
         }

         return 0;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

      ROW = row;
      COL = col;

      int result = 0;

      int start=0, end=cells.size()-1;

      while(start<=end)
      {
        int mid = start+(end-start)/2;

        if(checkpass(mid,cells))
        {
            result = mid+1;
            start = mid+1;
        }
        else
        end = mid-1;

      }

      return result;
        
    }
};