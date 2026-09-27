class Solution {
public:
    
    int find(int i,int j,string &txt,string &pat)
    {
        // Base cases
        if(i==txt.size() && j==pat.size())
        return 1;
        if(j==pat.size())
        return 0;
         
        if(j+1<pat.size() && pat[j+1]=='*')
        {
            int not_take = find(i,j+2,txt,pat);
            int take = (i<txt.size() && (txt[i]==pat[j] || pat[j]=='.')) && find(i+1,j,txt,pat);

            return not_take||take;
        }

        else if(i<txt.size() && (txt[i]==pat[j] || pat[j]=='.'))
        {
            if(find(i+1,j+1,txt,pat))
            return 1;

            return 0;
        }
        else
        {
            return 0;
        }

    }

    bool isMatch(string txt, string pat) {
        return find(0,0,txt,pat);
    }
};