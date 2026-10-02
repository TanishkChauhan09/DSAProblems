class Solution {
public:
   
    // Top-down. Memoization
    
    int n;
    vector<long long >dp;

    long long find(int index, vector<vector<int>>&que)
    {
        // Base condition
        if(index >= n)
         return 0;
        
        // optimization
        if( dp[index] != -1)
         return dp[index];

        long long take = que[index][0] + find( index + que[index][1]+1 , que); 
        long long notTake = find(index+1, que);

        return  dp[index] = max(take, notTake);
    }

    long long mostPoints(vector<vector<int>>& questions) {

        n = questions.size();
        dp.resize(n+1, -1);

        return find(0, questions);
        
    }
};