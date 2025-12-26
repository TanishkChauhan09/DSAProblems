class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        //countint Total Y
        int totalY = 0;
        for(char c : customers)
         {
            if(c == 'Y') totalY++;
        }
        
        int openN = 0;
        int closedY = totalY;
        
        int minPenalty = totalY;  // j = 0 case
        int ans = 0;
        
        //her, I am trying closing at each hour
        for(int j = 1; j <= n; j++) 
        {
            char prev = customers[j-1];
            
            if(prev == 'N') openN++;
            else closedY--;
            
            int penalty = openN + closedY;
            
            if(penalty < minPenalty) 
            {
                minPenalty = penalty;
                ans = j;
            }
        }
        
        return ans;
    }
};
