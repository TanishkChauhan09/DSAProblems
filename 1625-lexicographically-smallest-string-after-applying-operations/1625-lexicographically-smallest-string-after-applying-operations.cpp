class Solution {
public:

   // simply BFS lgaaye hai generally aisi problems me graph lgta hai aur mostly BFS/DFS se hojaata hai
    
    void rotate(string &str, int b)
    {
        reverse(str.begin(), str.end());
        reverse(str.begin() , str.begin()+b );
        reverse(str.begin()+b, str.end());
    }

    string findLexSmallestString(string s, int a, int b) {

        string smallestString = s;

        unordered_set<string>st;
        st.insert(s);

        queue<string>q;
        q.push(s);

        while(!q.empty())
        {
            string str = q.front();
            q.pop();

            if(smallestString > str)
            {
                smallestString = str;
            }

            // adding 'a' integer at odd position of a string
            string temp = str;
            for(int i=1; i<temp.size(); i+=2)  // odd position pr traverse krna hai toh 1 se start krnege and 2 ka jump lete jaayenge string ki end tk
            {
                temp[i] = (((temp[i]-'0')+a)%10)+'0';
            }

            if(st.find(temp)==st.end())
            {
                st.insert(temp);
                q.push(temp);
            }

            // rotate the string by 'b' position
            rotate(str,b);   // rotate me str by reference paas kiya hai toh jo str queue se nikaala tha and jo rotate hua hai dono alag alag hojaayenge
            if(st.find(str)==st.end())
            {
                st.insert(str);
                q.push(str);
            }
        }
        
        return smallestString;
    }
};