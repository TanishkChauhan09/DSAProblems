class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;

        int totalSeats = 0;
        for (char c : corridor)
            if (c == 'S') totalSeats++;

        
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;

        long long ways = 1;
        int seatCount = 0;   
        int plants = 0;      
        bool inGap = false;  

        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;

                if (seatCount % 2 == 1 && inGap) {
                    ways = (ways * (plants + 1)) % MOD;
                    plants = 0;
                    inGap = false;
                }

                if (seatCount % 2 == 0) {
                    inGap = true;
                }
            }
            else { 
                if (inGap) {
                    plants++;
                }
            }
        }

        return ways;
    }
};
