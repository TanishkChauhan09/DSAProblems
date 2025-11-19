class Solution {
public:

    bool valid(int i,int j,int n,int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    
    int dr[4] = {0,0,-1,1};
    int dc[4] = {1,-1,0,0};

    int minimumEffortPath(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        dp[0][0]=0;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;                           
        
        pq.push({0,{0,0}});
        
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            pq.pop();
            
            if(visited[row][col])
            continue;
            
            visited[row][col]=1;
            
            if(row==n-1 && col==m-1)
            return wt;
            
            for(int k=0;k<4;k++)
            {
                int n_row = row+dr[k];
                int n_col = col+dc[k];
                
                if(valid(n_row,n_col,n,m) && !visited[n_row][n_col])
                {
                    
                    dp[n_row][n_col] = max(wt , abs(mat[row][col]-mat[n_row][n_col]));

                    pq.push({dp[n_row][n_col],{n_row,n_col}});
                }
            }
        }
        
        return -1;
    }
};