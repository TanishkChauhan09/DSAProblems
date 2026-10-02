class Solution {
public:
   
    
    // LCS jaisa hi concept use ho rha hai
    // BOTTOM-UP

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>>dp;

        dp.resize(n+1, vector<int>(m+1, 0));

        // tabulation

        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(nums1[i] == nums2[j])
            {
                 dp[i][j]  =  1 +  dp[i+1][j+1];   //find(i+1, j+1, temp1, temp2);
            }
            else
            {
                int poss1  =  dp[i][j+1];          // find(i+1, j, temp1, temp2);
                int poss2 =   dp[i+1][j];          // find(i, j+1, temp1, temp2);

               dp[i][j]  = max( poss1, poss2);
            }
            }
        }

        // return find(0, 0, nums1, nums2);

        return dp[0][0];
    }
};