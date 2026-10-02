class Solution {
public:
    
    // Bottom-up/Tabulation

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();
        
        vector<int>dp;
        dp.resize(n+1, 0);

        // tabulation

        for(int index=n-1; index >=0; index--)
        {
            int result = INT_MIN;

            result = max(result, stoneValue[index] -   dp[index+1] );

            if(index+1 < n)
                result = max(result, stoneValue[index] + stoneValue[index+1] -  dp[index+2] ) ;

            if(index+2 < n)
                result = max(result, stoneValue[index] + stoneValue[index+1] + stoneValue[index+2] - dp[index+3] ) ;

             dp[index] = result;
        }
        
        // int diff =  find(0, stoneValue); // isme ye record rkhne ki need nhi hai ke alice chalegi ya bob kyuki me jo phli function call lga rha hoon wo index 0 se and ( add krke - finction_call ) wo alice ko hi show kr rhi hai  and alternative me bhi alice hi rhegi

        int diff = dp[0];

        if(diff >0)
         return "Alice";

        else if(diff <0)
         return "Bob";

        else
         return "Tie";  

    }
};