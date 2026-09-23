class Solution {
public:

   // using binary search on answers(2D matrix)
   // isme hmm ye dekhne ke jya uss decided time me (0,0) se (n-1,m-1) pr pahuch skte hai
   
    int drow[4] = {0,0,1,-1};
    int dcol[4] = {1,-1,0,0};
    
    int isPossible(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&visited,int mid)
    {

        if(visited[i][j] || grid[i][j]>mid)
        {
            return 0;
        }

        if(i==n-1 && j==m-1)
            return 1;

        visited[i][j] = 1;

        for(int k=0;k<4;k++)
        {
            int n_row = i + drow[k];
            int n_col = j + dcol[k];

            if( n_row<0 || n_row>=n || n_col<0 || n_col>=m)
            continue;

            if(isPossible(n_row,n_col,n,m,grid,visited,mid))
            return 1;
            
        }

        return 0;
    }

    
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int start=0 , end = n*n , ans=0;

        while(start<=end)
        {
            int mid = start+(end-start)/2;
            
            vector<vector<int>>visited(n,vector<int>(m,0));
            if(isPossible(0,0,n,m,grid,visited,mid))
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
            
        }
       
        return ans;
        
    }
};