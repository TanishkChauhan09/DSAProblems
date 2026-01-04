class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int n : nums) {

            // ✅ Case 1: n = p^3
            int p = round(cbrt(n));
            if ((long long)p * p * p == n && isPrime(p)) {
                ans += (1 + p + p*p + n);
                continue;
            }

            // ✅ Case 2: n = p * q (distinct primes)
            for (int d = 2; d * d <= n; d++) {
                if (n % d == 0) {
                    int other = n / d;
                    if (d != other && isPrime(d) && isPrime(other)) {
                        ans += (1 + d + other + n);
                    }
                    break;
                }
            }
        }

        return ans;
    }
};
