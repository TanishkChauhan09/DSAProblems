class Solution {
public:
    
    int dfs(int node,vector<vector<int>>&adj,vector<int>&visited)
    {
        visited[node]=1;
        int min_ele = node;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];
            if(!visited[neigh])
            {
                int neigh_min = dfs(neigh,adj,visited);
                min_ele = min(min_ele,neigh_min);
            }
        }
        return min_ele;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        vector<vector<int>>adj(26);
        
        for(int i=0;i<n;i++)
        {
            int u = s1[i]-'a';
            int v = s2[i]-'a';

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        string result="";
        for(int i=0;i<baseStr.size();i++)
        {
            vector<int>visited(26,0);
            int minele = dfs(baseStr[i]-'a',adj,visited);

            result.push_back(minele+'a');
        }

        return result;
        
    }
};