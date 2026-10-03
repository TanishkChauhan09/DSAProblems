class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       
        int n = nums.size();

        if(n <1)
        { 
            return {0};
        }

        vector<int> temp(n);
        temp[0] = nums[0];

        int size =1;

        for(int i=1;i<n;i++)
        {
            int start = 0 , end = size-1 , index = size;

            while(start <= end)
            {
                int mid = start + (end - start)/2;

                if(temp[mid] < nums[i])
                {
                    // agr index = 0 le rha hai toh index = mid+1 yahan likhna pdega
                    start = mid+1;
                }
                else
                {
                    index = mid; // index me size le rhe ai toh index = mid yahan krna pdega
                    end = mid -1;
                }
            }

           temp[index] = nums[i];

            if(index == size)
            {
                size++;
            }

        }
        
        return size;
    }
};
