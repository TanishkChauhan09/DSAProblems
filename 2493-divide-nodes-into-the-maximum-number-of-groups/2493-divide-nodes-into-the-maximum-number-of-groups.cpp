class Solution {
public:
   
    int BiPartite(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&colors)
    {
        visited[node]=1;

        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];
            if(!visited[neigh])
            {
                colors[neigh] = (colors[node]+1)%2;
                if(BiPartite(neigh,adj,visited,colors)==0)
                {
                    return 0;
                }
            }
            else
            {
                if(colors[node]==colors[neigh])
                  return 0;
            }
        }

        return 1;
    }


    int bfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&path)
    {
        visited[node]=1;
        path[node]=1;

        queue<int>q;
        q.push(node);

        int label = 1;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                int node = q.front();
                q.pop();

                for(int j=0;j<adj[node].size();j++)
                {
                    int neigh = adj[node][j];

                    if(!visited[neigh])
                    {
                        visited[neigh] = 1;
                        path[neigh] = 1;
                        q.push(neigh);
                    }
                }
            }
            label++;
        }

        return label-1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // check Bipartite for each components agr koi bhi bipartite nhi hota hai toh we will simply return -1
        vector<int>colors(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colors[i]==-1)
            {
                vector<int>visited(n,0);
                colors[i] = 0;
                if(BiPartite(i,adj,visited,colors)==false)
                   return -1;
            }
        }

        // Agr bipartite graphs hue toh ab hmaara ans possible hai
        // finding labels for each component
        int ans=0;
        vector<int>visited(n,0);
        for(int i=0;i<n;i++)
        {
            int maxLabelOfGroup = 0;
            vector<int>path(n,0);

            if(visited[i]==0)
            {
                maxLabelOfGroup = max(maxLabelOfGroup,bfs(i,adj,visited,path));

                for(int j=0;j<n;j++)
                {
                    if(path[j] && j!=i)
                    {
                        vector<int>newvisited(n,0);
                        vector<int>localPath(n,0);
                        maxLabelOfGroup = max(maxLabelOfGroup,bfs(j,adj,newvisited,localPath));
                    }
                }
            }

            ans += maxLabelOfGroup;
        }

        return ans;
    }
};