class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size();
        int i=0, maxfreq=0, curr_len=0, ans=0;
        unordered_map<int,int>mp;

        for(int j=0;j<n;j++)
        {
            mp[s[j]]++;
            maxfreq = max(maxfreq,mp[s[j]]);
            curr_len+=1;

            while(curr_len-maxfreq>k)
            {
                mp[s[i]]--;
                maxfreq = max(maxfreq,mp[s[i]]);
                i++;
                curr_len--;
            }
            ans = max(ans,curr_len);
        }
        return ans;
    }
};