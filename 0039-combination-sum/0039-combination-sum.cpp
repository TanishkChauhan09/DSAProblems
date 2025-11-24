class Solution {
public:

    void find(int index,vector<int>&arr,int n,int target,vector<vector<int>>&ans,vector<int>subs)
    {
        // Base case
        if(index==n)
        {
            if(target==0)
            ans.push_back(subs);

            return;
        }
        
        if(index>=n || target<0)
        return;
     
        find(index+1,arr,n,target,ans,subs);
        subs.push_back(arr[index]);
        find(index,arr,n,target-arr[index],ans,subs);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();

        vector<vector<int>>ans;
        vector<int>subs;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

        find(0,candidates,n,target,ans,subs); 

        return ans;
    }
};