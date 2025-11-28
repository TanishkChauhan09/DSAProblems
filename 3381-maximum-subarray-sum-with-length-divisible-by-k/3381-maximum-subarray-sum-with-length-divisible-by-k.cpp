class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long maxi = LLONG_MIN;

        vector<long long>psum(n,0);
        psum[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            psum[i] = psum[i-1]+nums[i];
        }

        for(int start=0;start<k;start++)
        {
            int i=start;
            long long ps=0;

            while(i<n && i+k-1<n)
            {
                int j = i+k-1;
                ps += psum[j]- ((i>0)?psum[i-1]:0);

                maxi = max(maxi,ps);
                if(ps<0)
                 ps=0;

                i+=k; 
            }
        }
        return maxi;
    }
};