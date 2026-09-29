class Solution {
public:
 
    // Memoization
    vector<vector<int>>dp;
    
    int find(int index, string &str, int &n, char prevStr)
    {
        if( index >= n)
          return 0;

        // optimization
        if(dp[index][prevStr - '0'] != -1)
        {
            return dp[index][prevStr-'0'];
        }  

        int flip = INT_MAX;
        int notflip = INT_MAX;  

        if(str[index] == '0')
        {
            if(prevStr == '0')
            {
                flip = 1 + find(index+1, str, n, '1'); // 0 ko flip krdiya toh ab aage wale ke liye previous 1 hoga
                notflip = find(index+1, str, n, '0');
            }
            else
            {
                flip = 1 + find(index+1, str, n, '1'); 
            }
        }  
        else if(str[index] == '1')
        {
            if(prevStr == '0')
            {
                flip = 1 + find(index+1, str, n, '0'); // 0 ko flip krdiya toh ab aage wale ke liye previous 1 hoga
                notflip = find(index+1, str, n, '1');
            }
            else
            {
                notflip = 0 + find(index+1, str, n, '1'); 
            }
        }

        return dp[index][prevStr - '0'] = min(flip, notflip);
    }

    int minFlipsMonoIncr(string s) {
        
        int n = s.size();

        dp = vector<vector<int>>(n+1, vector<int>(2,-1));   // char type ka bhi bnaaya tha pr wo overflow de rha hai toh kyu na map bna le

        return find(0, s, n, '0');
    }
};