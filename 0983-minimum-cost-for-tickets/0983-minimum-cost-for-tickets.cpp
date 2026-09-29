class Solution {
public:
    
    // Recusion and Top-down

    // Memoization
    vector<int>dp;
   
    int find(int index, vector<int>&days, vector<int>&costs, int &n)
    {
        // Base condition
        if(index >= n)
          return 0;

        // optimization
        if(dp[index] != -1)
          return dp[index];  
        
        // on 1st day
        int day_1 = costs[0] + find(index+1, days, costs, n);

        // on 2nd day
        int  j = index;
        int maxDayToTravel = days[index] + 7;

        while( j<n && days[j] < maxDayToTravel)
           j++;

        int day_2  = costs[1] + find(j, days, costs, n); 

        // on 3rd day
        j = index;
        maxDayToTravel = days[index] + 30;

        while( j<n && days[j] < maxDayToTravel)
           j++;
           
        int day_3  = costs[2] + find(j, days, costs, n); 

        return  dp[index] = min( { day_1 , day_2 , day_3 } );
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        int n = days.size();

        dp.resize(n+1 , -1);

        return find(0, days, costs, n);
        
    }
};