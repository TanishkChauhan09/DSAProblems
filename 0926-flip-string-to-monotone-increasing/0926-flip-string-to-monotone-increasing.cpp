class Solution {
public:
 
    // bottom up
    
    // jb 1 aaye tb bss countones ko increase kro ye mt dekhi ke flip krron ya na kroon

    // jb bhi 0 aaye tb dekho agr 0 hi rhne deta hoon toh aage ke countones sbhi ko 0 krna pdega aur agr 0 ko flip krdeta hoon toh flip+1 aur lgg jaayega

    int minFlipsMonoIncr(string s) {
        
        int n = s.size();
         
        int countones = 0;
        int flips = 0;

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
              countones++;
            else if(s[i] == '0')
            {
                
                flips = min( countones, flips + 1);
            }  
        } 
        
        return flips;
    }
};