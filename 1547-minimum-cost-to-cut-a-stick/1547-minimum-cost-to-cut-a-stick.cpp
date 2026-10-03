class Solution {
public:
    
    int find(int left,int right,vector<int>&new_cuts,vector<vector<int>>&dp)
    {
        // Base condition
        if(right-left<=1)
        return 0;

        if(dp[left][right]!=-1)
        return dp[left][right];

        // logic
        int ans = INT_MAX;
        for(int k=left+1;k<right;k++)
        {
            int cuts = (new_cuts[right]-new_cuts[left])+find(left,k,new_cuts,dp)+find(k,right,new_cuts,dp);
            
            ans = min(cuts,ans);
        }

        return dp[left][right] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        
        sort(cuts.begin(),cuts.end());
        vector<int>new_cuts;
        new_cuts.push_back(0);

        for(int i=0;i<cuts.size();i++)
        {
            new_cuts.push_back(cuts[i]);
        }
        new_cuts.push_back(n);

        int left=0, right=new_cuts.size();

        // Recursion+Top-Down(Memoization)
        int m = new_cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));  // for initialisation we just fill the complete dp with 0
        
        // logic
        for(int i=m-1+1;i>=0;i--)
        {
            for(int j=i+2;j<m;j++)
            {
                // also need to write this if starting j loop from i+1 , this will not be needed if 'j' loop will be starting from i+2
                // if(j-i<=1)
                // continue;

                int ans = INT_MAX;
                for(int k=i+1;k<j;k++)
                {
                    int cuts = (new_cuts[j]-new_cuts[i])+dp[i][k]+dp[k][j]; 
                    
                    ans = min(cuts,ans);
                }

                 dp[i][j] = ans;
            }
        }
 
  
        return dp[0][m-1];
    }
};