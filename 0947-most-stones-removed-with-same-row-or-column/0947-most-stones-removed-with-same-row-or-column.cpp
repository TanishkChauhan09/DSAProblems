class Solution {
public:
    
    // using dfs only
    void dfs(int index,int n, vector<vector<int>>&stones,vector<int>&visited)
    {
        visited[index] = 1;

        for(int j=0;j<stones.size();j++)
        {
            int row = stones[j][0];
            int col = stones[j][1];

            if(!visited[j] && (stones[index][0]==row || stones[index][1] == col))
            {
                dfs(j,n,stones,visited);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();

        vector<int>visited(n,0);

        int groups = 0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(i,n,stones,visited);
                groups++;
            }
        }
        
        // count will tell ke kiyne groups hai kyuki jitni baar dfs call lgegi utne hi groups honge
        return n-groups;
    }
};