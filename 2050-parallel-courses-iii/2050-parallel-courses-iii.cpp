class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(int i=0;i<relations.size();i++)
        {
            int u = relations[i][0]-1;
            int v = relations[i][1]-1;
            adj[u].push_back(v);  // u--->v edge
            indegree[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(!indegree[i])
            {
                q.push(i);
            }
        }

        vector<int>timeToCompleteEarlierCourse(n,0);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j];
                timeToCompleteEarlierCourse[neigh] = max(timeToCompleteEarlierCourse[neigh],timeToCompleteEarlierCourse[node]+time[node]);

                indegree[neigh]--;
                if(!indegree[neigh])
                {
                    q.push(neigh);
                }
            }
        }

     
      int res = 0;

      for(int i=0;i<n;i++)
      {
          res = max(res,timeToCompleteEarlierCourse[i]+time[i]);
      }

      return res;

        
    }
};