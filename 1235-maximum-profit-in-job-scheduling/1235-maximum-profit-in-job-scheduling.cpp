class Solution {
public:

    
    // dp+ BINARY SEARCH
  int solve(int i, vector<vector<int>>& jobs, vector<int>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        // binary search to find last non-overlap
        int l = 0, r = i - 1, last = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (jobs[mid][1] <= jobs[i][0]) {
                last = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        int includeProfit = jobs[i][2] + solve(last, jobs, dp);
        int excludeProfit = solve(i - 1, jobs, dp);

        return dp[i] = max(includeProfit, excludeProfit);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>> jobs(n);

        for(int i = 0; i < n; i++)
        {
            jobs[i] = { startTime[i], endTime[i], profit[i] };
        }

        //  MUST sort by the ending times
         sort(jobs.begin(), jobs.end(), [&](auto &a, auto &b){
            return a[1] < b[1];
        });

        vector<int> dp(n, -1);

        return solve(n - 1, jobs, dp);

    }
};