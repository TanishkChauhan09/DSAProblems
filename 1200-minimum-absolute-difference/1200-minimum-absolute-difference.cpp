class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
     {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int mindiff = INT_MAX;

        // fiinding minimum difference
        for (int i = 1; i < n; i++) {
            mindiff = min(mindiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> ans;

        // collecting all pairs with min difference
        for (int i = 1; i < n; i++)
         {
            if (arr[i] - arr[i - 1] == mindiff)
             {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }

        return ans;
    }
};
