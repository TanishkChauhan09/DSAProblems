
#include<algorithm>
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        long long result=0;

        long long sum=0;
        for(int i=0;i<batteries.size();i++)
         sum+=batteries[i];

        long long start = 1;

        long long end = sum/(long long)n;


        while(start<=end)
        {
            long long mid = start+(end-start)/2;
            
            long long mintimerequire = (long long)n*mid;
            long long tempsum = 0;
            for(int i=0;i<batteries.size();i++)
            {
                tempsum+=min((long long)batteries[i],mid);
            }

            if(tempsum>=mintimerequire)
            {
                result = mid;
                start = mid+1;
            }

            else
            end = mid-1;

        }

        return result;
        
    }
};