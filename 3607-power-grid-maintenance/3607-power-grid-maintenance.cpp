class Solution {
public:

    // dfs se kra hai
    // set me se erase krne pr time comp log(size of set) hoti hai


    void dfs(int node, vector<vector<int>>&adj, vector<int>&visited, unordered_map<int,set<int>>&mp, vector<int>&nodeID,int id)
    {
        visited[node] = 1;
        mp[id].insert(node);
        nodeID[node] = id;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(!visited[neigh])
            {
                dfs(neigh,adj,visited,mp,nodeID,id);
            }
        }
    }

    vector<int> processQueries(int n, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        
        vector<vector<int>>adj(n+1);  // 1 indexed hai
        for(int i=0; i<connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, set<int>>mp;
        vector<int>visited(n+1,0);
        vector<int>nodeID(n+1,0);
        int id = 1;

        for(int i=1; i<=n; i++)  // 1 indexed hai
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,mp,nodeID,id);
                id++;
            }
        }

        vector<int>ans;

        // traversing on queries
        for(int i=0;i<queries.size();i++)
        {
            int type = queries[i][0];
            int node = queries[i][1];

            if(type==1)
            {
                int id = nodeID[node];
                if(mp[id].count(node))
                {
                    ans.push_back(node);
                }
                else if(!mp[id].empty())
                {
                    int startingNode = *(mp[id].begin());
                    ans.push_back(startingNode);
                }
                else
                {
                    ans.push_back(-1);
                }
            }
            else
            {
                int id = nodeID[node]; // phle node ki id nikaalenge then uske baad uss id se node ko delete krenge
                mp[id].erase(node);  // ordered set me se erase krne ki time comp log(size of set) hoti hai
            }
        }

        return ans;
    }
};