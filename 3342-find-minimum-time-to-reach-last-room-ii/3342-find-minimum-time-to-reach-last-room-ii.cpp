class Solution {
public: 

    // Dijkstra algorithm on 2D matrix 
    // isme hint ye hoti hai ke single source diya hua hai and destination bhi
    // graph ko matrix me bhi represent kr skte hai jiska kuch weight hota hai

    // greedy yahan kaam nhi krega kyuki agr hmm bss minimum ke basis pr hi chle gye phle hi kya pta aage hme kahin bdi distance miljaaye chah toh hmm kmm rhe the pr mil jyada gyi isliye sbhi me se jo minimum hai wo phle aaye uske liye priority wueue le lenge 

    int minTimeToReach(vector<vector<int>>& grid) {
        int drow[4] = {0,0,1,-1};
        int dcol[4] = {1,-1,0,0};

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        vector<vector<int>>explored(n,vector<int>(m,0));
        result[0][0] = 0;

        priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>>pq; 

        pq.push({0,{0,{0,0}}});

        while(!pq.empty())
        {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second.first;
            int adjacent = pq.top().second.second.second;

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

                int maxAnsPoss = max(time, grid[n_row][n_col]) + (adjacent+1); // +1 for the time to move in the next cell

                if( result[n_row][n_col] > maxAnsPoss )
                {
                    result[n_row][n_col] = maxAnsPoss;
                    pq.push({maxAnsPoss , { n_row,{n_col , adjacent==0 ?1 :0} }});
                }
            }
        }
        
        return result[n-1][m-1];
    }
};