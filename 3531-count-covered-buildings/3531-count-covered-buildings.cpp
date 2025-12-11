class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        vector<int>x_min(n+1,n);
        vector<int>y_min(n+1,n);
        vector<int>x_max(n+1,0);
        vector<int>y_max(n+1,0);

        for(int i=0;i<buildings.size();i++)
        {
            int x = buildings[i][0];
            int y = buildings[i][1];

            x_min[x] = min(x_min[x],y);
            x_max[x] = max(x_max[x],y);
            y_min[y] = min(y_min[y],x);
            y_max[y] = max(y_max[y],x);

        }

        int count=0;

        for(int i=0;i<buildings.size();i++)
        {
            int a = buildings[i][0];
            int b = buildings[i][1];

            if((x_min[a]<b) && (x_max[a]>b) && (y_min[b]<a) && (y_max[b]>a))
            {
                count++;
            }
        }

        return count;

    }
};