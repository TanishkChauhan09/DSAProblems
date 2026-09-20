class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        if(grid[0][1]>1 && grid[1][0]>1)
        return -1;

        int drow[4] = {0,0,1,-1};
        int dcol[4] = {1,-1,0,0};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        vector<vector<int>>explored(n,vector<int>(m,0));
        result[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; 

        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if(row==n-1 && col==m-1)
            return result[n-1][m-1];

            if(explored[row][col])
            continue;

            explored[row][col] = 1;

            for(int k=0;k<4;k++)
            {
                int n_row = row + drow[k];
                int n_col = col + dcol[k];

                if(n_row<0 || n_row>=n || n_col<0 || n_col>=m || explored[n_row][n_col])
                continue;

                if(grid[n_row][n_col] <= time+1)
                {
                    result[n_row][n_col] = time+1;
                    pq.push({time+1 , { n_row,n_col }});
                }
                else if( (grid[n_row][n_col]-result[row][col])%2==0)   // or else if( (grid[n_row][n_col]-time)     // even 
                {
                    result[n_row][n_col] = grid[n_row][n_col] + 1;
                    pq.push({ grid[n_row][n_col] + 1 , { n_row,n_col }} );
                }
                else if( (grid[n_row][n_col]-result[row][col])%2==1)  // or else if( (grid[n_row][n_col]-time)%2==1)      // odd 
                {
                    result[n_row][n_col] = grid[n_row][n_col];
                    pq.push({ grid[n_row][n_col] , { n_row,n_col }} );
                }
            }
        }
        
        return result[n-1][m-1];
    }
};