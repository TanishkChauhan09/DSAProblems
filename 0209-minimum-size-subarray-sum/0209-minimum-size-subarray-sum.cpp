class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        // brute force
        int ans=INT_MAX, i=0, sum=0;
        
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];

            if(sum>=target)
            ans = min(ans,j-i+1);

            // if sum >= target try to get a smaller window so shrink it
            while(sum>=target)
            {
                sum-=nums[i];
                ans = min(ans,j-i+1);
                i++;
            }
        }

        return ans==INT_MAX?0 : ans;
    }
};