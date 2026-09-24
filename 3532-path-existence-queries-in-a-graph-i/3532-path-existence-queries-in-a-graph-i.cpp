class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int>component(n,-1);
    
        int componentID = 0;
        component[0] = componentID;
        
        // every node will gets its own component
        for(int i=1; i<n; i++)
        {
            if( nums[i]-nums[i-1] > maxDiff)
               componentID++;

            component[i] = componentID;
        }

        // traversing on queries
        vector<bool>result;

        for(int i=0; i<queries.size(); i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            result.push_back( component[u] == component[v]);
        }

        return result;
        
    }
};