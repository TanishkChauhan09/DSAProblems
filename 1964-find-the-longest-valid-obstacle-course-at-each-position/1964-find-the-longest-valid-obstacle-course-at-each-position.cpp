class Solution {
public:

    // time complexity O(n^logn) hai.

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        int n = obstacles.size();

        if(n <1)
        { 
            return {0};
        }

        vector<int> ans(n,0);
        ans[0] = 1;

        vector<int> temp(n);
        temp[0] = obstacles[0];

        int size =1;

        for(int i=1;i<n;i++)
        {
            int start = 0 , end = size-1 , index = 0;

            while(start <= end)
            {
                int mid = start + (end - start)/2;

                if(temp[mid] <= obstacles[i])
                {
                    index = mid +1;
                    start = mid+1;
                }
                else
                {
                    end = mid -1;
                }
            }

           temp[index] = obstacles[i];

            if(index == size)
            {
                size++;
            }

            ans[i] = index + 1;
        }
        
        return ans;
    }
};