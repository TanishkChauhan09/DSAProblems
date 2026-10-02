class Solution {
public:
    
    // top-down/ Memoization
    vector<int>dp;

    int n;

    int find(int index, vector<int>&stoneValue)
    {
        // Base condition
        if(index >= n)
         return 0;

        if(dp[index] != -1)
         return dp[index]; 

        int result = INT_MIN;

        result = max(result, stoneValue[index] -  find(index+1,stoneValue) );

        if(index+1 < n)
             result = max(result, stoneValue[index] + stoneValue[index+1] -  find(index+2,stoneValue) ) ;

        if(index+2 < n)
            result = max(result, stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] -  find(index+3,stoneValue) ) ;

        return dp[index] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {

        n = stoneValue.size();

        dp.resize(n+1, -1);
        
        int diff =  find(0, stoneValue); // isme ye record rkhne ki need nhi hai ke alice chalegi ya bob kyuki me jo phli function call lga rha hoon wo index 0 se and ( add krke - finction_call ) wo alice ko hi show kr rhi hai  and alternative me bhi alice hi rhegi

        if(diff >0)
         return "Alice";

        else if(diff <0)
         return "Bob";

        else
         return "Tie";  

    }
};