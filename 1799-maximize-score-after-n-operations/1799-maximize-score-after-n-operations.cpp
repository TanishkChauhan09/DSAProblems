class Solution {
public:
    
    // Top-down : isme imp concept bhi hai ke array ke age koi elements ko leliya toh aage function call me kaise pta kre toh uske liye ek visited vector lenge and jiss index ke elements ko use kr liya hai unko mark 1 krdenge and then uss visited ko next function call me mark krdenge pr fir code me ye bhi condiiton likhni hogi ke agr already visited hai toh continue kro lo hi mtt unhe

    int n;

    // Memoization : isme visited vector ki state same aa skti hai isiliye usi ke basis pe memoize krdiya

    map< vector<int>, int> mp;  // UNORDERED MAP ERROR DE RHA THA READ NOTES

    int find(vector<int>&nums, vector<int>&visited, int operation)
    {
        if( mp.find(visited) != mp.end())
         return mp[visited];

        int maxAns = 0;

        for(int i=0; i<=n-2 ;i++)  // i<n pe bhi shi chal rha hai
        {
            if(visited[i])
              continue;

            for(int j=i+1; j<n; j++)
            {
                if(visited[j])
                 continue;

                visited[i] = 1;
                visited[j] = 1;
                int res = operation * gcd( nums[i], nums[j]);

                int poss = find(nums, visited, operation+1);

                maxAns = max( maxAns, res+poss);

                // Backtracking : but very important to keep use it
                visited[i] = 0;
                visited[j] = 0; 
            }
        }

        return mp[visited] = maxAns;
    }

    int maxScore(vector<int>& nums) {
        
        n = nums.size();
        vector<int>visited(n,0);

        mp.clear(); // map ko clear krlenge

        int operation = 1;

        return find(nums, visited, operation);
    }
};