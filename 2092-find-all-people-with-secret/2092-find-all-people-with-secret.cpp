class Solution {
public:

    // ALGORITHM TO SOLVE QUESTION
    
    // 1.) sort on the basis of meeting time
    // 2.) male a graph of all people doing meeting at the particular time aise hi ek ek krke sbhi time pe jiss people ki bhi meeting chal rhi hai unka graph bnaayenge
    // 3.) Ab jiss people ko secret pta hai unnhe queue me daal denge and ab BFS apply kr denge
    // 4.) Ab jo extra people secret jaanenge unhe visited set me daal denge 
    // 5.) and ab jo visited hue hai usss set pe traverse krke unke knowsecret vector me true mark kr denge
    // 6.) Ab jo secret jaan gya honge unko ek result vector me daal denge and iss result vector ko return kr denge

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
