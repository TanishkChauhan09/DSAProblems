class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        // should be of long long
        vector<long long>prefix(n+1,0);
        int i=0;
        deque<int>dq;

        int ans=INT_MAX;

        for(int j=0;j<n;j++)
        {
            if(j==0){
                prefix[j] = nums[0];
            }
            else{
                prefix[j] = prefix[j-1]+nums[j];
            }

            // store the ans if we got the prefix[j]>=k and then see does window needs to shrink or not
            if(prefix[j]>=k)
            ans = min(ans,j+1);

            while(!dq.empty() && prefix[j]-prefix[dq.front()]>=k)
            {
                ans = min(ans,j-dq.front());
                dq.pop_front();
            }

           while(!dq.empty() && prefix[dq.back()]>=prefix[j])
            {
                dq.pop_back();
            }

            dq.push_back(j);
        }

        return ans==INT_MAX?-1 :ans;
    }
};
