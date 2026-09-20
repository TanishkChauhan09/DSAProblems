class Solution {
public:

   // 2D matrix pe dijkstra algorithm apply kiya hai( Explored lgaake thoda optimiza krne ki kosis ki hai)

    int minimumObstacles(vector<vector<int>>& grid) {

        int drow[4] = {0,0,-1,1};
        int dcol[4] = {1,-1,0,0};
        
        int n = grid.size();       // Number of rows
        int m = grid[0].size();    // Number of columns
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        result[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});  // {wt,{row,col}}

        
        // for little optimization in DFS solution
        vector<vector<int>>explored(n,vector<int>(m,0));

        while(!pq.empty())
        {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(explored[row][col])
            continue;

            explored[row][col] = 1;

            for(int k=0;k<4;k++)
            {
                int n_row = row + drow[k];
                int n_col = col + dcol[k];

                if(n_row<0 || n_row>=n || n_col<0 || n_col>=m || explored[n_row][n_col])    // also here for optimization
                continue;

                int wt = (grid[n_row][n_col]==1)? 1: 0;

                if(result[n_row][n_col] > (wt + result[row][col]))
                {
                    result[n_row][n_col] = (wt + result[row][col]);   // wt + dist bji likh skte the wo bhi shi hota
                    pq.push({wt + result[row][col] , {n_row,n_col} } );  // pq.push({reuslt[n_row][n_col] , {n_row,n_col}})
                }
            }
        }
        
        return result[n-1][m-1];
    }
};