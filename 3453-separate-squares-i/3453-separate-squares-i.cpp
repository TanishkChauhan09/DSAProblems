class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) 
    {
        double low = 1e18, high = -1e18;

        // Determining search space
        for (auto &s : squares) 
        {
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        // Binary search
        for (int iter = 0; iter < 80; iter++) 
        {  
            double mid = (low + high) / 2.0;

            double below = 0.0, above = 0.0;

            for (auto &s : squares) 
            {
                double y = s[1];
                double l = s[2];

                if (mid >= y + l) 
                {
                    below += l * l;
                }
                else if (mid <= y) 
                {
                    above += l * l;
                }
                else 
                {
                    double h1 = mid - y;
                    double h2 = (y + l) - mid;
                    below += h1 * l;
                    above += h2 * l;
                }
            }

            if (below < above)
                low = mid;
            else
                high = mid;
        }

        return (low + high) / 2.0;
    }
};
