class Solution {
public:

   // O( n*(2^n))  time complexity
   vector<string>ans;


   bool valid(string str)
   {
       int count=0;
       for(int i=0;i<str.size();i++)
       {
           char ch = str[i];
           if(ch == '(')   // char ka dhyaan rkhna hai
             count++;

           if(ch == ')')
             count--;

           if(count<0)
              return 0;    
       }

       return count==0;
   }

   void find(int n,string &str)
   {
        if( 2*n == str.size() )
        {
            if(valid(str))
            {
                ans.push_back(str);
            }
            return;
        }

        str.push_back('(');
        find(n,str);
        str.pop_back();

        str.push_back(')');
        find(n,str);
        str.pop_back();

   }
     


    vector<string> generateParenthesis(int n) {
        
        string str = "";

        find(n,str);

        return ans;
        
    }
};