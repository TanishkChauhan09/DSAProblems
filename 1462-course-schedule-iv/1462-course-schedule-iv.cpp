class Solution {
public:

    
    // by applying dfs hrr query ke liye ke kya graph me src(phle wale se) dest(dusre wale pr) pr pahuch ske hai ya nhi agr pahuch ske hai toh hmm kah ske ke src(u) wala prerequisite hai dest(v) ka

    // kyuki graph directed bnaya prerequisite ke basis pr hi

    int dfs(int src,int dest,vector<vector<int>>&adj,vector<int>&visited)
    {
        if(src==dest)
        return 1;

        visited[src]=1;

        // traversing on the neighbour
        for(int j=0;j<adj[src].size();j++)
        {
            int neigh = adj[src][j];

            if(!visited[neigh])
            {
                if(dfs(neigh,dest,adj,visited))
                 return 1;
            }
        }

        return 0;

    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>>adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<bool>ans(queries.size(),0);

        for(int i=0;i<queries.size();i++)
        {
            int src = queries[i][0];
            int dest = queries[i][1];

            vector<int>visited(numCourses,0);
            if(dfs(src,dest,adj,visited))
            {
                ans[i] =1;
            }
        }
        
        return ans;
    }
};