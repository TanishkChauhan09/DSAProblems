class Solution {
public:

    int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        
        unordered_map<int,int>mp; 
        for(int i=0;i<points.size();i++)
        {
            mp[points[i][1]]++;
        }

        long long ans=0;
        long long total_sum=0;

        for(auto &it : mp)
        {
            long long count = it.second;
            long long horizontal_line = (count*(count-1))/2;

            ans += (horizontal_line*total_sum);
            total_sum += horizontal_line;
        }

        return ans % mod;
    }
};