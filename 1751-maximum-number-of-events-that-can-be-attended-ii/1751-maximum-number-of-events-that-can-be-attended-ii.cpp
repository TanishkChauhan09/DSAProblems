class Solution {
public:

   // top-down/ Memoization

   vector<vector<int>>dp;
    
    int n;

    int find(int idx, vector<vector<int>>&events, int k)
    {
        // Base condition
        if(idx >=n || k==0)
          return 0;

        if(dp[idx][k] != -1) 
          return dp[idx][k];  

        int skip = find(idx+1, events, k);

        int start = events[idx][0];
        int end = events[idx][1];
        int value = events[idx][2];


        // Binary search
        int first = idx+1, last = n-1, nextidx=n;

        while(first <= last)
        {
            int mid = first + (last-first)/2;

            if(events[mid][0] > end)
            {
                nextidx = mid;
                last = mid-1;
            }
            else
              first = mid+1;
        }
        
        //  LINEAR SEARCH

        // for( ; j<n; j++)
        // {
        //     if(events[j][0] > end)
        //       break;  
        // }  

        int take = value + find(nextidx, events, k-1);

        return  dp[idx][k] =  max(skip, take);
    }


    int maxValue(vector<vector<int>>& events, int k) {
        
        n = events.size();

        dp.resize(n+1, vector<int>(k+1, -1));

        // don't forget to sort the evnts array on the basis of start time , generally interval wale questions aasan pddd jaate hai
        sort(begin(events), end(events));

        return find(0,events,k);
    }
};