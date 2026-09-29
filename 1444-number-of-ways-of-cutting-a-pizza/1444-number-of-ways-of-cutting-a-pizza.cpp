class Solution {
public:

    // Recursion  and Top-Down

    // MEmoization
    vector<vector<vector<int>>>dp;
    
    vector<vector<int>>apples;
    int m,n;

    int mod = 1e9 +7;

    int find(int i, int j, int k)
    {
        // Base condition : number of apples [i][j] of apples me k se greater ya equal hone chahiye tbhi toh sbhi person ko atleast 1 apple de paunga wrna nhi de paunga
        if(apples[i][j] < k)
          return 0;

        // agr ek hi person rah gya hai toh mujhe ye dekhna hoga ke apples me kmm se kmm ek apple toh ho
        if(k == 1)
        {
            if(apples[i][j] >= 1)
              return 1;

            return 0;  
        } 

        // OPTIMIZATION
        if(dp[i][j][k] != -1)
          return dp[i][j][k];

        int ans = 0; 

        // horizontal cut
        for(int h = i+1; h<m; h++)
        {
            int lowerApples = apples[h][j];
            int upperApples = apples[i][j] - lowerApples;

            if(upperApples >= 1  && lowerApples >= k-1)
            {
                ans = (ans %mod + find(h, j, k-1) %mod ) %mod ;
            }
        }

        // vertical cut
        for(int v = j+1; v<n; v++)
        {
            int rightApples = apples[i][v];
            int leftApples = apples[i][j] - rightApples;

            if(leftApples >= 1  && rightApples >= k-1)
            {
                ans = (ans %mod + find(i, v, k-1) %mod )%mod ;
            }
        }

        return dp[i][j][k]  =  ans%mod;
    }

    int ways(vector<string>& pizza, int k) {

        int M = pizza.size();     // no. of rows
        int N = pizza[0].size();  // no. of cols

        m = M;
        n = N;

        dp.resize(55,vector<vector<int>>(55, vector<int>(20,-1)));

        apples = vector<vector<int>>(55, vector<int>(55,0));

        // filling the apple vector for counting the number of apples
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                apples[i][j] = apples[i][j+1];  

                for(int l=i; l<m; l++)
                {
                    if(pizza[l][j] == 'A')
                    {
                        apples[i][j] += 1;
                    }  
                }
            }
        }

        return find(0, 0, k);
        
    }
};