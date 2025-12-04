class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        
        int n = points.size();
        unordered_map<float,vector<float>>mp;
        map<pair<float,float>,vector<float>>duplicates; // strong mid points co-ordinates with slopes as a value

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                float slope,intercept;

                if(x1==x2)
                {
                    slope = 1e8+7;
                    intercept = x1;
                }
                else
                {
                    int dx = x2-x1;
                    int dy = y2-y1;

                    slope = (float)dy/dx;
                    intercept = (float)((y1*dx) - (x1*dy))/dx;
                }

                mp[slope].push_back(intercept);
                float midpoint_x = (x1 + x2) / 2.0;
                float midpoint_y = (y1 + y2) / 2.0;

                duplicates[{midpoint_x, midpoint_y}].push_back(slope);

            }
        }

        int ans=0;

        for(auto &it : mp)
        {
            map<float,int>count;

            for(auto i:it.second)
            {
                count[i]++;
            }
            
            int prev_lines=0;
            for(auto &it2:count)
            {
                int points = it2.second;
                ans += (points*prev_lines);

                prev_lines+=points;
            }
        }

        // int ans2=0;

        for(auto &it : duplicates)
        {
            map<float,int>count;

            for(auto i:it.second)
            {
                count[i]++;
            }
            
            int prev_lines=0;
            for(auto &it2:count)
            {
                int points = it2.second;
                ans -= (points*prev_lines);

                prev_lines+=points;
            }
        }

        return ans;
    }
};