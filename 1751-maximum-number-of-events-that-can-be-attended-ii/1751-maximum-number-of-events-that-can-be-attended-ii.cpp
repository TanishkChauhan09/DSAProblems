class Solution {
public:
    int n;
    vector<vector<int>> t;
    vector<int> nextIdx;

    int solve(vector<vector<int>>& events, int i, int k) {
        
        if(k <= 0 || i >= n)
            return 0;
        
        int start = events[i][0];
        int end   = events[i][1];
        int value = events[i][2];
        
        if(t[i][k] != -1)
            return t[i][k];
        
        // finding the next event which we can attend
        int j = nextIdx[i];
        
        int take = value + solve(events, j, k-1);
        int skip = solve(events, i+1, k);
        
        return t[i][k] = max(take, skip);
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        
        n = events.size();
        nextIdx.resize(n);

        for(int i = 0; i < n; i++) {
            nextIdx[i] = upper_bound(begin(events), end(events), 
                          vector<int>{events[i][1], INT_MAX, INT_MAX}) - begin(events);
        }
        
        t.resize(n+1, vector<int>(k+1, -1));
        
        return solve(events, 0, k);
    }
};