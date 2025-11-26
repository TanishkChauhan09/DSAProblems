class Solution {
public:
    
    int countPalindromicSubsequence(string s) {
        
        int n = s.size();
        vector<int>used(26,0);

        // this is used to store the last index of any character that is present in the string
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
          mp[s[i]] = i;

        int count=0;
 
        for(int i=0;i<n;i++)
        {
            if(!used[s[i]-'a'])
            {
                used[s[i]-'a']=1;
                int last_idx = mp[s[i]];

                if(last_idx==i)
                continue;

                set<int>st;
                for(int j=i+1;j<last_idx;j++)
                {
                    st.insert(s[j]-'a');
                }

                count+=st.size();
            }
        }

        return count;
    }
};