class Solution {
public:
     
    // O(n^2) time comp 

    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        
        // EDGE CASE
        if(n<=2)
         return n;

        unordered_map<int,int> mp[n]; // array which is having of type map
        
        int ans = 2;

        for(int i=1; i<n; i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                int diff = nums[i] - nums[j];

                if(mp[j].find(diff) != mp[j].end())
                {
                    mp[i][diff] = max(mp[i][diff], mp[j][diff] + 1);
                    ans = max(ans, mp[i][diff]);
                }
                else
                {
                    if(mp[i].find(diff) == mp[i].end() ) // need this cond as well agr i pr bhi nhi hai 
                       mp[i][diff] = 2;
                }
            }
        }

        return ans;
    }
};