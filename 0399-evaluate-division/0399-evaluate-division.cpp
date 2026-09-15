class Solution {
public:
    
    void dfs(string src,string dest,unordered_map<string,vector<pair<string,double>>>&adj,unordered_set<string>&visited,double product,double &ans)
    {
        if(visited.find(src)!=visited.end())
        {
            return;
        }

        visited.insert(src);

        if(src==dest)
        {
            ans = product;
            return;
        }

        for(auto &p:adj[src])
        {
            string  neigh = p.first;
            double val = p.second;

            dfs(neigh,dest,adj,visited,product*val,ans);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }

        vector<double>result;

        for(int i=0;i<queries.size();i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];

            double product = 1.0;
            double ans = -1.0;

            if(adj.find(src)!=adj.end())
            {
                unordered_set<string>visited;
                dfs(src,dest,adj,visited,product,ans);
            }
            
            result.push_back(ans);
        }

        return result;
        
    }
};