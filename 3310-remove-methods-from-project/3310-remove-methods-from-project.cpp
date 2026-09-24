class Solution {
public:
    
    // using Kahn's Algorithm

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0; i<invocations.size(); i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        // apply bfs from the suspicious node
        queue<int>q;
        vector<int>suspicious(n,0);

        q.push(k);
        suspicious[k] = 1;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int j=0; j<adj[node].size(); j++)
            {
                int neigh = adj[node][j];
                indegree[neigh]--;

                if(suspicious[neigh] == 0)  // agr wo abhi suspicios me nhi aaya pr suspicious uspr jaa skta hai
                {
                    q.push(neigh);
                    suspicious[neigh] = 1;
                }
            }
        }

        bool flag = 1;
        vector<int>ans;
        
        for(int i=0; i<n; i++)
        {
            if( suspicious[i] && indegree[i] > 0)
            {
                flag = 0;
                break;
            }
            if( !suspicious[i] )  // agr koi node suspicious hai hi nhi toh usse toh ans me daalna pdega
              ans.push_back(i);
        }

        if( flag==0 )
        {
            vector<int>temp;
            for(int i=0; i<n; i++)
            {
                temp.push_back(i);
            }
            return temp;
        }

        return ans;
    }
};