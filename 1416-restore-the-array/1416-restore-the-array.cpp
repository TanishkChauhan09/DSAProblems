class Solution {
public:
   
    // Recursion , MCM ki tarah hai

    // Top- doen / Memoization
    vector<int>dp;
   
    int mod = 1e9+7;

    int find(int index, string &s, int k)
    {
        // Base condition
        if(index >= s.size())
         return 1; // iska matlab hmne possible range me poori string ko divide kr diya hoga kyuki range dekh hi diveide kr rhe hai phle hi

        // leading 0 bhi nhi hona chahiya
        if( s[index] == '0')
          return 0; 

        // OPTIMIZATON
        if(dp[index] != -1)
          return dp[index];  

        long long num = 0;
        int ans = 0;

        for(int j = index; j < s.size(); j++)
        {
            num  =  ( num *10 ) + ( s[j] -'0');

            if(num  > k)
              break;

            ans = ( ans + find(j+1, s, k) % mod) %mod;  
        } 

        return  dp[index] = ans;
    }
    int numberOfArrays(string s, int k) {

        dp.resize( s.size()+1 , -1);
        
        return find(0 , s, k) % mod;
    }
};