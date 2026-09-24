class Solution {
public:
    
    // using DFS
    
    int drow[4] = {0,0,1,-1};
    int dcol[4] = {1,-1,0,0};

    int dfs(int prow, int pcol, int n, int m, vector<vector<char>>&grid, vector<vector<int>>&visited, int parentr,int parentc)
    {
        visited[prow][pcol] = 1;

        for(int k=0; k<4; k++)
        {
            int n_row = prow + drow[k];
            int n_col = pcol + dcol[k];

            if(n_row == parentr && n_col == parentc)
              continue;

            if( n_row>=0 && n_col>=0 && n_row<n && n_col<m && (grid[prow][pcol] == grid[n_row][n_col]))
            {
                if(visited[n_row][n_col])
                return 1;

                if(dfs(n_row, n_col, n, m, grid, visited,prow,pcol))
                  return 1;
            }
        } 

        return 0;
    }

    bool containsCycle(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && dfs(i,j,n,m,grid,visited,-1,-1))
                {
                    return 1;
                }
            }
        }

        return 0;
        
    }
};