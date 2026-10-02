class Solution {
public:
   
    
    // LCS jaisa hi concept use ho rha hai
    // Top-down / Memoization

    vector<vector<int>>dp;

    int n;
    int m;

    int find(int i, int j, vector<int>&temp1, vector<int>&temp2)
    {
        // Base condition
        if(i >= n || j>= m)
        {
            return 0;
        }

        // optimization

        if( dp[i][j] != -1)
         return dp[i][j];

        if(temp1[i] == temp2[j])
        {
            return dp[i][j]  =  1 + find(i+1, j+1, temp1, temp2);
        }
        else
        {
            int poss1  = find(i+1, j, temp1, temp2);
            int poss2 = find(i, j+1, temp1, temp2);

            return  dp[i][j]  = max( poss1, poss2);
        }
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        n = nums1.size();
        m = nums2.size();

        dp.resize(n+1, vector<int>(m+1, -1));

        return find(0, 0, nums1, nums2);
    }
};