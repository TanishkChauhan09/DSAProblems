class Solution {
public:
    
    void find(vector<int>&nums,vector<int>temp,vector<vector<int>>&ans,int n,vector<int>visited)
    {
        // base case
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }

        // logic
        for(int j=0;j<n;j++)
        {
            if(visited[j]) continue;

            temp.push_back(nums[j]);
            visited[j] = 1;
            find(nums,temp,ans,n,visited);
            visited[j]=0;
            temp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

      int n = nums.size(); 
      vector<vector<int>>ans;
      vector<int>visited(n,0);
      vector<int>temp;
      find(nums,temp,ans,n,visited);

      return ans;  
    }
};