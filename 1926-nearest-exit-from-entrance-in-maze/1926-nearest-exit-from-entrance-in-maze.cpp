class Solution {
public:
    
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};

    bool valid(int r,int c,int n,int m)
    {
        return r>=0 && c>=0 && r<n && c<m;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        if(maze[entrance[0]][entrance[1]]=='+')
        {
            return -1;
        }
        
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});

        maze[entrance[0]][entrance[1]]='+';

        int step=0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if((r==0 || r==n-1 || c==0 || c==m-1) && !(r==entrance[0] && c==entrance[1]))
                {
                   return step;
                }

                for(int k=0;k<4;k++)
                {
                    int nr = r+row[k];
                    int nc = c+col[k];

                    if(valid(nr,nc,n,m) && maze[nr][nc]=='.')
                    {
                        maze[nr][nc]='+';
                        q.push({nr,nc});
                    }
                }
            }
            
            step++;
        }

        return -1;
        
    }
};