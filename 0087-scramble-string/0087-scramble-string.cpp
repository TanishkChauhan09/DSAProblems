class Solution {
public:

    // Recursion and Top-down

    // Memoization
    unordered_map< string ,bool >mp;
   
    int find(string s1, string s2)
    {
        // Base condition , age dono string equal aa jaati hai toh return 1
        if(s1 == s2)
          return 1;
        
        // age dono string ki length hi same nhi hai toh fir unhe convert kiya jaana hi possible nhi hai isiliye return 0
        if(s1.size() != s2.size())
          return 0;

        string key = s1 + "_" + s2; // uniqueness bnnane ke liye aisa kiya hai

        if(mp.find(key) != mp.end())
        {
            return mp[key];
        }
        
        int n = s1.size();

        for(int i=1; i<n; i++)
        {
            bool notSwapped = find( s1.substr(0,i) , s2.substr(0,i))   &&  find( s1.substr(i,n-i) , s2.substr(i,n-i));

            if(notSwapped)
              return mp[key] = 1;

            bool swapped =  find( s1.substr(0,i) , s2.substr(n-i,i))   &&  find( s1.substr(i,n-i) , s2.substr(0,n-i));  

            if(swapped)
              return mp[key] = 1;
        }    

        return mp[key] = 0;
    }

    bool isScramble(string s1, string s2) {
        
        return find(s1, s2);
    }
};