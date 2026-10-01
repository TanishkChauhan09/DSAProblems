class Solution {
public:
   
//STATE OF DP[INDEX]: dp[index] = s[index...n-1] ko valid arrays mein divide karne ke total ways

    // Top- doen / Memoization
    vector<int>dp;
   
    int mod = 1e9+7;  
    
    int numberOfArrays(string s, int k) {

        int n = s.size();

        dp.resize( n+1 , 0);
        // BASE CONDITION -> INITIALIZATON
        dp[n] = 1;  // kyuki jb index n ke brabr aur jyada jaa rha tha tb m 1 return kr de rha tha toh phle hi store krlenge usko

        // Tabulation
        for(int index = n-1; index >= 0; index--)
        {
            long long num = 0;
            int ans = 0;

            // don't forget to handle leading zeros case
            if( s[index] == '0')
             continue;

            for(int j = index; j < s.size(); j++)
            {
                num  =  ( num *10 ) + ( s[j] -'0');

                if(num  > k)
                  break;

                ans =  ( ans  + dp[j+1] %mod) %mod;  // ( ans + find(j+1, s, k) % mod) %mod;  
            } 

           dp[index] = ans %mod;
        }
        
        // return find(0 , s, k) % mod;

        return dp[0];
    }
};