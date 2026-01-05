class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long total = 0;
        int negCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int x : row) {
                total += abs(x);
                if (x < 0) negCount++;
                minAbs = min(minAbs, abs(x));
            }
        }

        // If odd number of negatives, one smallest abs stays negative
        if (negCount % 2 == 1) {
            total -= 2LL * minAbs;
        }

        return total;
    }
};
