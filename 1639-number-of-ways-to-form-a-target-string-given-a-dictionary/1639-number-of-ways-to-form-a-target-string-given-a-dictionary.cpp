class Solution {
public:

   // Bottom up/ Tabulation


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
     
        int n = words[0].size();
        int m = target.size();

        dp.resize(n+2, vector<int>( m+2, 0));

        // base condition -> initialization
        for(int i = 0; i <= n; i++)
        {
            dp[i][m] = 1;
        }

        // dictionary columns complete
        for(int i = 0; i <= m; i++)
        {
            dp[n][i] = 0;
        }

        dp[n][m] = 1;

        // hrr jth index of word in words sbhi character ki kya frequency rhegi uska count nikaal kr 2-D vector freq me store kr rhe hai

        vector<vector<int>> freq( 26, vector<int>( n+1) );

        for(int col=0; col <n; col++)
        {
            //  usme word me & nhi lgaa tha jiis se words me se hrr baar copy bnn rhi thi aur isiliye yhi main the mle dene ke picche ka kaaaradddd
            for(string  &word : words)
            {
                int row = word[col]-'a';

                freq[row][col]++;
            }
        }

        // Tabulation

        for(int dict_j=n-1 ; dict_j >= 0; dict_j--)
        {
            for(int trgt_i = m-1; trgt_i >= 0; trgt_i--)
            {
                int nottaken = dp[dict_j+1][trgt_i] %mod; //find(dict_j+1, trgt_i, target, n, freq) % mod;

                 long long taken = (1LL * (freq[target[trgt_i]-'a'][dict_j] ) %mod * dp[dict_j+1] [trgt_i+1]%mod ) %mod;// (1LL * (freq[target[trgt_i]-'a'][dict_j] ) %mod * find(dict_j+1, trgt_i+1, target, n, freq) %mod ) %mod;

                dp[dict_j][trgt_i] = ( nottaken + 1LL * taken )%mod; 
            }
        }

        // return find(0, 0, target, n, freq) % mod;
        return dp[0][0] %mod;
    }
};