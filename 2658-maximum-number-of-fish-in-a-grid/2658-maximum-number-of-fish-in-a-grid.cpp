class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int ans = INT_MIN;
        bool flag = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    flag = 1;
                    break;
                }
            }
        }

        if(!flag)
        return 0;

        int drow[4] = {0,0,1,-1};
        int dcol[4] = {1,-1,0,0};

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int countFish = 0;

                if(grid[i][j]!=0)
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});

                    countFish = grid[i][j];
                    grid[i][j] = 0;

                    while(!q.empty())
                    {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        for(int k=0;k<4;k++)
                        {
                            int n_row = row + drow[k];
                            int n_col = col + dcol[k];

                            if(n_row<0 ||n_row>=n ||n_col<0 || n_col>=m || grid[n_row][n_col]==0)
                            continue;

                            countFish += grid[n_row][n_col];
                            grid[n_row][n_col] = 0;

                            q.push({n_row , n_col});

                        }
                    }
                }

                ans = max(ans,countFish);
            }
        }
        
        return ans;
    }
};