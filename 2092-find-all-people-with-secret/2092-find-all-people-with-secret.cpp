class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // sort meetings by time
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        int i = 0;
        int m = meetings.size();

        while (i < m) 
        {
            int time = meetings[i][2];

            // graph for same-time meetings
            unordered_map<int, vector<int>> graph;
            unordered_set<int> people;

            // collect all meetings at this time
            while (i < m && meetings[i][2] == time)
             {
                int u = meetings[i][0];
                int v = meetings[i][1];
                graph[u].push_back(v);
                graph[v].push_back(u);
                people.insert(u);
                people.insert(v);
                i++;
            }

            // BFS only from people who already know the secret
            queue<int> q;
            unordered_set<int> visited;

            for (int p : people) 
            {
                if (knows[p])
                {
                    q.push(p);
                    visited.insert(p);
                }
            }

            // spread secret in this time group
            while (!q.empty()) 
            {
                int curr = q.front();
                q.pop();
                for (int nei : graph[curr])
                {
                    if (!visited.count(nei))
                    {
                        visited.insert(nei);
                        q.push(nei);
                    }
                }
            }

            // update knowledge AFTER finishing this time
            for (int p : visited)
             {
                knows[p] = true;
            }
        }

        // collect result
        vector<int> ans;
        for (int i = 0; i < n; i++) 
        {
            if (knows[i])
                ans.push_back(i);
        }

        return ans;
    }
};
