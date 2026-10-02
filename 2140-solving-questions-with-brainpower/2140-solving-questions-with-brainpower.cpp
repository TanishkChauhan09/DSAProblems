class Solution {
public:
   
    // Top-down. Memoization
    
    int n;
    vector<long long >dp;

    long long mostPoints(vector<vector<int>>& questions) {

        n = questions.size();
        dp.resize(n+1, 0);

        // tabulation

        for(int index=n-1; index>=0 ;index--)
        {
            long long take = questions[index][0] +  dp[ min(index + questions[index][1]+1, n)];   // min wala logic lgaana accha hai kyuki chahe kitna bhi extra jaaye aana toh 0 hi jo already [index][n] pe 0 already hai
            long long notTake =  dp[index+1];   

            dp[index] = max(take, notTake);
        }

        // return find(0, questions);
        return dp[0];
        
    }
};