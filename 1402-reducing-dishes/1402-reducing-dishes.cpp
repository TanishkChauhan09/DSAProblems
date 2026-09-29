class Solution {
public:
    
    // Recursion and Top-down

    // Memoization
    vector<vector<int>>dp;
    
    int find(int index, vector<int>&satisfaction, int time)
    {
        if(index >= satisfaction.size())
        {
            return 0;
        }

        // Optimization
        if(dp[index][time] != -1)
          return dp[index][time];

        int include = satisfaction[index]*time + find(index+1, satisfaction, time+1);

        int exclude = find(index+1, satisfaction, time);

        return dp[index][time] = max(include , exclude);
    }

    int maxSatisfaction(vector<int>& satisfaction) {

        int n = satisfaction.size();
        int time = 1;

        // SORTING KRNI HAI ISME
        // kyuki m chahta hoon ke jiss dish ka satisfaction level bhut jyada hai wo jitna ho ske utne jyada time se multilpy ho and se tbhi ho skta hai jb wo dish array me sbse picche ho and isi ke liye me sort kr rha hoon

        sort(begin(satisfaction), end(satisfaction));

        dp.resize(n+1, vector<int>(n+1, -1));

        return find(0, satisfaction, time);
        
    }
};