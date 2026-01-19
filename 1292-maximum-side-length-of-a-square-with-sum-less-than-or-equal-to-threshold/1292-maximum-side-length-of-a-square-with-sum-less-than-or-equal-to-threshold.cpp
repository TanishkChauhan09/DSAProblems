class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        // Prefix sum matrix
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
               pre[i + 1][j + 1] = mat[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i][j];

            }
        }

        int low = 0, high = min(m, n), ans = 0;

        while (low <= high) 
        {
            int mid = (low + high) / 2;
            bool possible = false;

            for (int i = 0; i + mid <= m && !possible; i++) 
            {
                for (int j = 0; j + mid <= n; j++) 
                {
                    int sum = pre[i + mid][j + mid] - pre[i][j + mid]- pre[i + mid][j]+ pre[i][j];

                    if (sum <= threshold) 
                    {
                        possible = true;
                        break;
                    }
                }
            }

            if (possible) 
            {
                ans = mid;
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};
