class Solution {
public:

    unordered_map<string,vector<string>> adj;
    vector<string> result;

    void dfs(string fromAirport)
    {
        vector<string>& neighbours = adj[fromAirport];

        while(!neighbours.empty())
        {
            string toAirport = neighbours.back();
            neighbours.pop_back();

            dfs(toAirport);
        }

        result.push_back(fromAirport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        for(int i=0;i<tickets.size();i++)
        {
            string u = tickets[i][0];
            string v = tickets[i][1];

            adj[u].push_back(v);
        }

        // Reverse sorting
        // because we will take back()
        for(auto &edges : adj)
        {
            sort(edges.second.rbegin(),edges.second.rend());
        }

        dfs("JFK");

        reverse(result.begin(),result.end());

        return result;
    }
};