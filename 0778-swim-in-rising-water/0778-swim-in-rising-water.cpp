class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {


        int drow[4] = {0,0,1,-1};
        int dcol[4] = {1,-1,0,0};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        vector<vector<int>>explored(n,vector<int>(m,0));
        result[0][0] = 0;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; 

        pq.push({grid[0][0],{0,0}});  // 0 ki jagah grid[0][0] daala hai priority queue me

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

                 int maxAnsPoss = max(time, grid[n_row][n_col]) ;

                if( result[n_row][n_col] > maxAnsPoss )
                {
                    result[n_row][n_col] = maxAnsPoss;
                    pq.push({maxAnsPoss , { n_row,n_col }});
                }
            }
        }
        
        return result[n-1][m-1];
        
    }
};