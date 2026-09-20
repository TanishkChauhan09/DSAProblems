class Solution {
public:

   // 2D matrix pe dijkstra algorithm apply kiya hai

    int minimumObstacles(vector<vector<int>>& grid) {

        int drow[4] = {0,0,-1,1};
        int dcol[4] = {1,-1,0,0};
        
        int n = grid.size();       // Number of rows
        int m = grid[0].size();    // Number of columns
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        result[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});  // {wt,{row,col}}

        while(!pq.empty())
        {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            for(int k=0;k<4;k++)
            {
                int n_row = row + drow[k];
                int n_col = col + dcol[k];

                if(n_row<0 || n_row>=n || n_col<0 || n_col>=m)
                continue;

                int wt = (grid[n_row][n_col]==1)? 1: 0;

                if(result[n_row][n_col] > (wt + result[row][col]))
                {
                    result[n_row][n_col] = (wt + result[row][col]);   // wt + dist bji likh skte the wo bhi shi hota
                    pq.push({wt,{n_row,n_col}});
                }
            }
        }
        
        return result[n-1][m-1];
    }
};