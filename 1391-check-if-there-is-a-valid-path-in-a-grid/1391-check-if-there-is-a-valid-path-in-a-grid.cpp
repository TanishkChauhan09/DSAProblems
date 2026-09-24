class Solution {
public:

    unordered_map<int, vector<vector<int>> > directions = 
    {
        {1, { {0,-1},{0,1} }},
        {2, { {-1,0},{1,0} }},
        {3, { {0,-1},{1,0} }},
        {4, { {0,1},{1,0}  }},
        {5, { {0,-1},{-1,0} }},
        {6, { {-1,0},{0,1} }},
    };

    
    bool dfs(int i, int j,int n, int m, vector<vector<int>>&grid,vector<vector<int>>&visited)
    {
        if(i==n-1 && j==m-1)
          return 1;

        visited[i][j] = 1;  

         for(auto dir : directions[ grid[i][j] ])
         {
            int n_row = i + dir[0];
            int n_col = j + dir[1];

            if(n_row<0 || n_row>=n || n_col<0 ||n_col >=m || visited[n_row][n_col])
              continue;

            // ye bhut hi important check hai ke current (i,j) se hmm jiss adjacent pr jaana chahte hai kya uss pe se bhi current (i,j) pe aa skte hai tbhi toh usspr jaana benefit hai

             for(auto backdir : directions[ grid[n_row][n_col] ])
             {
                if( (backdir[0] + n_row == i) && (backdir[1] + n_col == j) ) // agr jaa skte hai tbhi dfs se uspr jaayenge
                {
                    if(dfs(n_row, n_col, n, m, grid, visited))
                       return 1;
                }
                 
             }
         } 

         return 0;
    }

    bool hasValidPath(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        return dfs(0,0,n,m,grid,visited);
        
    }
};