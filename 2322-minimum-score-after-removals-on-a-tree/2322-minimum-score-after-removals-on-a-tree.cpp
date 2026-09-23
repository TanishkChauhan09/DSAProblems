class Solution {
public:
    
    // isme hmm jo bhi do nodes ke pair ko select krenge toh usme hmm, jo node hai unke upr parent wali edge ko remove krenge iss se hmme always teen(3) component hi milenge

    // bss Jb dono nodes me se agr koi kisi ka ancestor hua tb uss case me subtree ka xor find krne me dikkat aayegi pr usko bhi handle ke lenge

    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&subtreeXOR,vector<int>&inTime,vector<int>&outTime,vector<int>&nums,int &time)
    {
        subtreeXOR[node] = nums[node];
        inTime[node] = time;
        time++;

        // traversing on neighbors
        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(neigh != parent)
            {
                dfs(neigh,node,adj,subtreeXOR,inTime,outTime,nums,time);
                subtreeXOR[node] ^= subtreeXOR[neigh];

            }
        }

        outTime[node] = time;
        time++;
    }

    bool isAncestor(int node1,int node2,vector<int>&inTime,vector<int>&outTime)
    {
        return inTime[node2]>=inTime[node1] && outTime[node1]>=outTime[node2];
    }

    int getmin(int xor1,int xor2,int xor3)
    {
        int maxXOR = max({xor1,xor2,xor3});
        int minXOR = min({xor1,xor2,xor3});

        return maxXOR-minXOR;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {

        int n = nums.size();

        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>subtreeXOR(n,0); // hr node ke subtree ka XOR bta dega directly

        // these both are for knowing whether someone is ancestor or not
        vector<int>inTime(n,0);
        vector<int>outTime(n,0);
        
        int time=0;
        dfs(0,-1,adj,subtreeXOR,inTime,outTime,nums,time); 

        int result = INT_MAX;

        // for every pair except parent(yahan 0 ko maana hai) kyuki parent ke upr toh koi edge nhi hogi isliye uss rhne denge
        for(int node1=1; node1<n; node1++)
        {
            for(int node2=node1+1; node2<n; node2++)
            {
                int xor1,xor2,xor3;

                if(isAncestor(node1,node2,inTime,outTime)) // kya node1 ancestor hai node2 ka
                {
                    xor1 = subtreeXOR[node2];                   // 1st component
                    xor2 = subtreeXOR[node1]^subtreeXOR[node2]; // 2nd component ,  same ka agr same se hi xor krte hai toh 0 aata hai , isme ye that ke node1 jo subtree tha usme node2 ke xor bhi aa rhe the kyuki node1 ancestor hai node2 ka toh isiliye hmne poore subtree ke xor ke saath jo uska part tha uska bhi xor kr diya jiss se wo ussme se htt gya
                    xor3 = subtreeXOR[0]^xor1^xor2;             // 3rd component
                }
                else if(isAncestor(node2,node1,inTime,outTime)) // kya node2 ancestor hai node1 ka
                {
                    xor1 = subtreeXOR[node1];                   // 1st component
                    xor2 = subtreeXOR[node2]^subtreeXOR[node1]; // 2nd component
                    xor3 = subtreeXOR[0]^xor1^xor2;             // 3rd component
                }
                else
                {
                    xor1 = subtreeXOR[node1];                   // 1st component
                    xor2 = subtreeXOR[node2];                   // 2nd component
                    xor3 = subtreeXOR[0]^xor1^xor2;             // 3rd component
                }

                result = min(result , getmin(xor1,xor2,xor3));
            }
        }
        
        return result;
    }
};