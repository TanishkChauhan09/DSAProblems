class Solution {
public:
    
    // Recursion + Top-Down

    vector<vector<int>>dp;

    int find(int index, int n, vector<int>&jobs,int days)
    {
        // Base case 
        // if only one day left then we have to complete all remaining jobs in that one day and fins the maximum form all of those
        if(days == 1)
        {
            int maxDiff = jobs[index];
            for(int i=index; i<n; i++)
            {
                maxDiff = max(maxDiff, jobs[i]);
            }
            return maxDiff;
        } 

        // Memoization
        if(dp[index][days] != -1)
          return dp[index][days];

        int maxDiff = jobs[index];
        int result = INT_MAX;
        
        // ye samajhna bhut jruri hai ke hme sbhi days me atleast one job toh complete krni hi hai uske liye hmm apne loop ko n-days pr rook denge taaki baaki ke remianing days me kmm se kmm ek job toh aaye think intuitively
        for(int i=index; i<=(n-days); i++)  
        {
            maxDiff = max(maxDiff, jobs[i]);
            
            int PossAns = maxDiff + find(i+1, n, jobs, days-1);

            result = min(result, PossAns);
        }

        return dp[index][days] = result;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        int n = jobDifficulty.size();
        if( n < d)
          return -1;

        dp = vector<vector<int>>(n+5, vector<int>(d+5,-1));  

        int ans = find(0,n,jobDifficulty,d);

        return ans;
    }
};