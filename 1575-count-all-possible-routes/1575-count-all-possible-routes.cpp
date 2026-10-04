class Solution {
public:
    
    // recursion

    // mistake
    // Agar fuel == 0 aur curr_idx == dest hai, toh woh valid route count hoga. Isliye pehle destination check karo. Also, agar remaining_fuel < 0 hai toh us route ko recursive call nahi karna chahiye ya fir condition for fuel ko bdlkr ye kr if(fuel <0) return 0;

    // idea: hmm ek baar start se suru krke kisi pr bhi jaa skte hai toh uske liye hrr ek par jaa ske and wahan se jo ans mila unhe add krdenge kyuki total chahiye uske liye loop chalaya hai recursion me 

    int mod = 1e9+7;
    int n;

    // memoization
    vector<vector<int>> dp;

    int find(int curr_idx, int dest, int fuel, vector<int>&locations)
    {
        // base condition : agr fuel khatm hogya toh kahin nhi jaa skta
        if(fuel < 0)
         return 0;

        if( dp[curr_idx][fuel] != -1)
          return dp[curr_idx][fuel]; 

        int ans = 0;

        if(curr_idx == dest)
          ans = 1;

        for(int i=0; i< n; i++)
        {
            if(i == curr_idx)
              continue;

            int remaining_fuel = fuel - abs(locations[i]- locations[curr_idx]);
            ans = ( ans %mod + find(i, dest, remaining_fuel, locations) %mod )%mod;  
        }   

        return  dp[curr_idx][fuel]  = ans % mod;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {

        n = locations.size();

        dp.resize(n+1, vector<int>(fuel+1, -1));

        return find(start, finish, fuel, locations) % mod;
        
    }
};