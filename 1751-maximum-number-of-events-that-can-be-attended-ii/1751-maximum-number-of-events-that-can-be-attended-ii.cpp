class Solution {
public:

    // Bottom-up / Tabulation
    vector<vector<int>>dp;

    int maxValue(vector<vector<int>>& events, int nk) {
        
        int n = events.size();

        dp.resize(n+1, vector<int>(nk+1, 0));

        // don't forget to sort the evnts array on the basis of start time , generally interval wale questions aasan pddd jaate hai
        sort(begin(events), end(events));


        // tabulation
        for(int idx =n-1; idx >=0 ;idx--)
        {
            for(int k = 1; k <=nk; k++) // k-1 needed tha isiliye k=1 se nk tk loop chalaya
            {
                int skip = dp[idx+1][k];

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

                int take = value + dp[nextidx][k-1];

                dp[idx][k] =  max(skip, take);
            }
        }


        // return find(0,events,k);
        return dp[0][nk];
    }
};