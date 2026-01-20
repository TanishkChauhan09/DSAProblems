class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int x : nums) 
        {
            // even numbers are impossible
            if ((x & 1) == 0)
             {
                ans.push_back(-1);
                continue;
            }

            // find lowest zero bit position
            int z = 0;
            while (x & (1 << z)) 
            {
                z++;
            }

            // z >= 1 always here
            ans.push_back(x - (1 << (z - 1)));
        }

        return ans;
    }
};
