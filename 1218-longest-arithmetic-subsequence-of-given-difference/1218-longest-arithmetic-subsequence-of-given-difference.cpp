class Solution {
public:

    //  bottom up / tabulation

    int longestSubsequence(vector<int>& arr, int difference) {
     
        int n = arr.size();
        
        unordered_map<int,int> mp;

        int ans = 1;
        
        for(int i=0;i<n;i++)
        {

            int lastele = arr[i] - difference;
            
            int length = mp[lastele];  // agr map me nhi hoga toh 0 aayega

            mp[arr[i]] = length + 1;

            ans = max(ans, mp[arr[i]]);
           
        }
        return ans;
    }
};