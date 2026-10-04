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

    int countRoutes(vector<int>& locations, int start, int finish, int fuelgiven) {

        n = locations.size();

        dp.resize(n+1, vector<int>(fuelgiven+1, 0));

        // tabulation
        for(int fuel = 0; fuel <= fuelgiven; fuel++)
        {
            for(int curr_idx=n-1; curr_idx>=0; curr_idx--) // fuel loop ki direction front se chalegi kyuki phle uss se phle waale needed  hai
            {
                int ans = 0;

                if(curr_idx == finish)
                ans = 1;

                for(int i=0; i< n; i++)
                {
                    if(i == curr_idx)
                    continue;

                    int remaining_fuel = fuel - abs(locations[i]- locations[curr_idx]);

                    if(remaining_fuel >= 0)
                    {
                        ans = (ans + dp[i][remaining_fuel]) % mod;
                    } 
                }   

                 dp[curr_idx][fuel]  = ans % mod;
            }
        }

        // return find(start, finish, fuel, locations) % mod;
        return dp[start][fuelgiven];
        
    }
};