class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // sliding window
        int n = nums.size();
        deque<int>dq;

        for(int i=0;i<k;i++)
        {
           while(!dq.empty() && nums[dq.back()]<=nums[i])
           {
              dq.pop_back();
           }
           dq.push_back(i);
        }

        vector<int>ans;
        // for the starting window push the maximum in the ans
        ans.push_back(nums[dq.front()]);

        for (int i = k; i < n; i++) 
        {

            // 1. remove elements out of this window
            while(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();

            // 2. Maintain decreasing order
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            // 3. push current element
            dq.push_back(i);

            // 4. front is max
            ans.push_back(nums[dq.front()]);
        }


        return ans;
    }
};