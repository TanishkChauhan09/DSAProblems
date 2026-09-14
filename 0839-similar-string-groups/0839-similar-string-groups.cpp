class Solution {
public:

    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited)
    {
        visited[node] = 1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(!visited[neigh])
            {
                dfs(neigh,adj,visited);
            }
        }
    }
    
    bool similar(string &str1,string &str2)
    {
        int n = str1.size();
        int different = 0;

        for(int i=0;i<n;i++)
        {
            if(str1[i]!=str2[i])
            {
                different++;
            }
        }

        if(different==2)
        return 1;
        
        if(different==0)
        return 1;

        return 0;
    }

    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(similar(strs[i],strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count=0;
        vector<int>visited(n,0);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
                count++;
            }
        }

        return count;
    }
};