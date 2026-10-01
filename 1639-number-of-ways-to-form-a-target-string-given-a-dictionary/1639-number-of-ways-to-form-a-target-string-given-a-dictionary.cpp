class Solution {
public:

    // long long + int mein normally koi overflow issue nahi hota, kyunki C++ int ko long long mein convert karke addition karta hai.

    // Haan, long long * int safe hai in normal C++ arithmetic. C++ int ko automatically long long mein convert kar deta hai:

    // Recursion and  Top-down


    // Memoization
    vector<vector<int>>dp;

    int mod = 1e9 + 7;
    
    int find(int dict_j, int trgt_i, string &target, int &n, vector<vector<int>>& freq)
    {
        // Base condition
        if(trgt_i == target.size())
         return 1;

        if(dict_j == n)
         return 0;

        // optimization
        if( dp[dict_j][trgt_i]  != -1)
         return dp[dict_j][trgt_i]; 


        int nottaken = find(dict_j+1, trgt_i, target, n, freq) % mod;

        long long taken = (1LL * (freq[target[trgt_i]-'a'][dict_j] ) %mod * find(dict_j+1, trgt_i+1, target, n, freq) %mod ) %mod;

        return dp[dict_j][trgt_i] = ( nottaken + 1LL * taken )%mod;  
    }

    int numWays(vector<string>& words, string target) {
        
        // words vector ki length nhi chahiye blki words vector me jo words hai ussme jo word hai uski length chahiye
        int n = words[0].size();
        int m = target.size();

        dp.resize(n+1, vector<int>( m+1, -1));

        // hrr jth index of word in words sbhi character ki kya frequency rhegi uska count nikaal kr 2-D vector freq me store kr rhe hai

        vector<vector<int>> freq( 26, vector<int>( n+1) );

        for(int col=0; col <n; col++)
        {
            for(string  &word : words)
            {
                int row = word[col]-'a';

                freq[row][col]++;
            }
        }

        return find(0, 0, target, n, freq) % mod;
    }
};