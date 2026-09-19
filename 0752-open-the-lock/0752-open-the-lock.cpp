class Solution {
public:

    // BY APPLYING BFS
    
    void findOtherPossibleCombination(string &str,queue<string>&q,unordered_set<string>&st)
    {
        // for all four position see the possible combinations by increasing and decreasing
        for(int i=0;i<4;i++)
        {
            char ch = str[i];

            // increase by 1
            str[i] = ch=='9'? '0': ch+1;
            if(st.find(str) == st.end())
            {
                st.insert(str);     
                q.push(str);
            }

            // decrease by 1
            str[i] = ch=='0'? '9': ch-1;
            if(st.find(str) == st.end())       // st.find() takes constant time
            {
                st.insert(str);
                q.push(str);
            }
            str[i] = ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {

        string start = "0000";

        unordered_set<string>st;    // or directly unordered_set<string>st(begin(deadends),end(deadends));
        for(int i=0;i<deadends.size();i++)
        {
            st.insert(deadends[i]);
        }

        if(st.find(start)!=st.end())
         return -1;

        queue<string>q;
        q.push(start);

        int label=0;

        while(!q.empty())
        {
            int n = q.size();

            while(n--)
            {
                string str = q.front();
                q.pop();

                if(str==target)
                return label;

                findOtherPossibleCombination(str,q,st);
            }
            label++;
        } 
        
        return -1;

    }
};