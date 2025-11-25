class Solution {
public:
   
    void find(vector<int>&arr,vector<int>&used,vector<int>temp,int n,vector<vector<int>>&ans)
    {
        // base condition
        if(temp.size()==n)
        {
            ans.push_back(temp);
            return;
        }

        // for loop to add more in the temp array
        for(int i=0;i<n;i++)
        {

            // condition, Add only ONE extra condition to avoid duplicates  :-> Jab 2 elements same ho (say 3,3) toh duplicate permutation avoid karne ke liye rule:
            if(i>0 && arr[i]==arr[i-1] && !used[i-1])
            continue;

            // i also need to pay attention that this for loop again start from the zero and it may add the already added element in the temp so to avoid this used this condition
            // already used in current permutation
            if (used[i]) continue;

            temp.push_back(arr[i]);
            used[i] = 1;

            find(arr,used,temp,n,ans);
            
             // BACKTRACKING
                used[i] = 0;
                temp.pop_back();   // should not be missing in your code
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        int n = nums.size();
        // sort the array
        sort(nums.begin(),nums.end());
        // making the used array to keep track whether the previous jo sort krne  se same bhi aagya hai used hua hai ya nhi 
        // kyuki agar wo used hua hai sirf tbhi hmm usko le skte hai 
        vector<int>used(n,0);
        
        vector<vector<int>>ans;
        vector<int>temp;

        find(nums,used,temp,n,ans);

        return ans;
    }
};