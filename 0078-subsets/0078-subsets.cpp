class Solution {
public:
   
    vector<vector<int>>result;

    void find(int n,vector<int>&nums,vector<int>&temp,int index)
    {
        // base case
         if(index >= n)
         {
            result.push_back(temp);
            return;
         }

         temp.push_back(nums[index]);
         find(n,nums,temp,index+1);

         temp.pop_back();

         find(n,nums,temp,index+1);
    }



    vector<vector<int>> subsets(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>temp;

        find(n,nums,temp,0);

        return result;

    }
};