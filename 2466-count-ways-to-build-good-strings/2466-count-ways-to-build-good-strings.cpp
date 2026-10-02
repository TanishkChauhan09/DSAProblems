class Solution {
public:
    
    // top-down/ Memoization
    vector<int>dp;
    int mod = 1e9 + 7;
    
    // MISTAKES
    // 1.) Ye condition C++ mein galat hai
    //     if(low <= temp1 <= high)
    //     C++ mein chained comparison Python ki tarah kaam nahi karta.
    //     Tumhe likhna hai:  if(low <= temp1 && temp1 <= high)

    // 2.) ans += 1 + p1 mein double counting ho rahi hai
    
    int find(int len, int &low, int &high, int &zerocnt, int &onecnt)
    {
        if(len > high)
         return 0;

        // optimization
        if(dp[len] != -1)
         return dp[len]; 

        int ans = 0; 

        int temp1 = len + zerocnt;
        int p1 = find(temp1, low, high, zerocnt, onecnt);

        if( low <= temp1 && temp1 <= high) 
        {
            ans = (1 + p1 ) %mod;
        }
        else
          ans = p1 %mod;

        int temp2 = len + onecnt;
        int p2 = find(temp2, low, high, zerocnt, onecnt);

        if( low <= temp2 &&  temp2 <= high) 
        {
            ans = (ans + 1 + p2 )%mod;
        }
        else
          ans = (ans + p2) %mod;  

        return dp[len] = ans %mod;  
    }

    int countGoodStrings(int low, int high, int zero, int one) {

        dp.resize(high+1 , -1);
        
        return find(0, low, high, zero, one) %mod;
    }
};