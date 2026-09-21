class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int drow[4] = {0,0,1,-1};
        int dcol[4] = {1,-1,0,0};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        result[0][0] = 0;  // remember this

        vector<vector<int>>explored(n,vector<int>(m,0));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});  

        while(!pq.empty())
        {
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1)
            return dist;      // result[n-1][m-1];  

            if(explored[row][col])
            continue;

            explored[row][col] = 1;

            // traversing in 4 direction
            for(int k=1;k<=4;k++)
            {
                int n_row = row + drow[k-1];
                int n_col = col + dcol[k-1];

                if(n_row<0 || n_row>=n || n_col<0 || n_col>=m || explored[n_row][n_col])
                 continue;

                //  int cost=0;
                 
                 // imp agr jis grid pe m jaana chahta hoon aur agr meri current grid uspr jaana allow hi nhi kr rhi toh cost me dist me 1 add krke daalunga wrna agr possible hua toh cost me 0 hi rhega ( edge wt bhi whi rhega)

                //  if( (grid[row][col]==1 && k!=1) || (grid[row][col]==2 && k!=2) || (grid[row][col]==3 && k!=3) || (grid[row][col]==4 && k!=4) )
                //  {
                //     cost = 1;
                //  }                    CAN REPLACE BY BELOW LINE

                 int cost = grid[row][col]!=k ? 1 : 0 ;
                 
                 // jb minim distance/cost aaye tbhi update kro

                 if(result[n_row][n_col] > dist+cost)
                 {
                    result[n_row][n_col] = dist + cost;  // or dist + cost

                    pq.push({ dist + cost , {n_row , n_col}});  // or pq.push({result[row][col] + cost , {n_row , n_col}});  or pq.push({result[n_row][n_col], {n_row , n_col}});
                 }

            }
        }
        
        return result[n-1][m-1];
    }
};