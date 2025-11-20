class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        
        int n = s.size();
        int m = t.size();

        int i=0,j=0;
        int cost=0, ans=0;
        
        while(j<n)
        {
            // increment
            cost += abs(s[j]-t[j]);
            // decrement the window if the current cost got increased by maxCost
            while(cost>maxCost)
            {
               cost -= abs(s[i]-t[i]);
               i = i+1;
            }

            // and keep storing the best possible ans
            ans = max(ans,j-i+1);

            j=j+1;
        }

        return ans;
        
    }
};