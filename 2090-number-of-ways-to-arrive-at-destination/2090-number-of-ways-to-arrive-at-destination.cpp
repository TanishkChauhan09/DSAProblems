#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const long long INF = 1e18;
        const int MOD = 1e9 + 7;

        // adjacency list: node -> {neighbor, weight}
        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // dist[i] = shortest time to reach i
        vector<long long> dist(V, INF);

        // ways[i] = number of shortest paths to reach i
        vector<long long> ways(V, 0);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top(); 
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &p : adj[node]) {
                int nxt = p.first;
                int wt  = p.second;

                // CASE 1: Found a better way
                if (dist[node] + wt < dist[nxt]) {
                    dist[nxt] = dist[node] + wt;
                    ways[nxt] = ways[node];
                    pq.push({dist[nxt], nxt});
                }
                // CASE 2: Found an equally short way
                else if (dist[node] + wt == dist[nxt]) {
                    ways[nxt] = (ways[nxt] + ways[node]) % MOD;
                }
            }
        }

        return ways[V-1] % MOD;
    }
};
