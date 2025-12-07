class Solution {
public:

    // back se recursion se solve krne pr and n-1,m-1 pass krne pr jiss se ki base case me 
    // less than , greater than ka sign aa gya hai so hmm isko dp me initialize nhi krskte hai toh 
    // meujhe base condition ko equals to ke sign me laana pdega so that fir hmm isko dp me initialize krke tabulation se krskte hai 

    int find(int i,int j,string &str,string &t,vector<vector<int>>&dp)
    {
        // Base case
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        // logic
        if(str[i]==t[j])
        return dp[i][j] = find(i-1,j-1,str,t,dp)+find(i-1,j,str,t,dp);
        else
        return dp[i][j] = find(i-1,j,str,t,dp);
    }

    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m =t.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1)); 

        return find(n-1,m-1,s,t,dp);
    }
};