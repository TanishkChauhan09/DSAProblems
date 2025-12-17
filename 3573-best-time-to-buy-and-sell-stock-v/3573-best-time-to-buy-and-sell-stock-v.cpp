class Solution {
public:
    // hmm yahan pr state ye bta rha h ke abhi hum kis transaction situation me hai

    // states are:
    // 0 -> free (no stock)
    // 1 -> long position (bought, need to sell)
    // 2 -> short position (sold, need to buy back)

    long long dp[1005][550][3];
    const long long NEG = -1e18;

    long long find(int index, vector<int>& prices, int k, int n, int state)
    {
        // base case
        if (index == n)
        {
            // agar free state me hai tabhi valid hai
            if (state == 0) return 0;
            // unfinished transaction is invalid
            return NEG;
        }

        if (k < 0) return NEG;

        if (dp[index][k][state] != -1)
            return dp[index][k][state];

        long long ans = NEG;

        // free state
        if (state == 0)
        {
            // option 1: do nothing
            ans = find(index + 1, prices, k, n, 0);

            // option 2: start long (buy)
            if (k > 0)
            {
                ans = max(ans,
                          -prices[index] + find(index + 1, prices, k - 1, n, 1));
            }

            // option 3: start short (sell)
            if (k > 0)
            {
                ans = max(ans,
                          prices[index] + find(index + 1, prices, k - 1, n, 2));
            }
        }

        // long state
        else if (state == 1)
        {
            // option 1: hold
            ans = find(index + 1, prices, k, n, 1);

            // option 2: sell and close long
            ans = max(ans,
                      prices[index] + find(index + 1, prices, k, n, 0));
        }

        // short state
        else
        {
            // option 1: hold
            ans = find(index + 1, prices, k, n, 2);

            // option 2: buy back and close short
            ans = max(ans,
                      -prices[index] + find(index + 1, prices, k, n, 0));
        }

        return dp[index][k][state] = ans;
    }

    long long maximumProfit(vector<int>& prices, int k)
    {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));

        return find(0, prices, k, n, 0);
    }
};
