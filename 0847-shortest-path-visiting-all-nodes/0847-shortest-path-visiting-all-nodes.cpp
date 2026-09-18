class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {

        int n = graph.size();
        queue<pair<int,int>>q;
        set<pair<int,int>>visited;

        for(int i=0;i<n;i++)
        {
            int maskvalue = 1<<i;
            q.push({i,maskvalue});

            visited.insert({i,maskvalue});
        }        

        int allNodeVisited = pow(2,n)-1;   // or (1<<n)-1

        int path=0;

        while(!q.empty())
        {
            int n = q.size();
            path++;

            while(n--)
            {
                pair<int,int> temp = q.front();
                q.pop();

                int currnode = temp.first;
                int currnodeMask = temp.second;

                vector<int>neighbours = graph[currnode];

                for(int j=0;j<neighbours.size();j++)
                {
                    int neigh = neighbours[j];
                    int neighMask = 1<<neigh;

                    int newMask = currnodeMask|neighMask;

                    if(newMask == allNodeVisited)
                    return path;
                    
                    if(visited.find({neigh,newMask})==visited.end())
                    {
                        visited.insert({neigh,newMask});
                        q.push({neigh,newMask});
                    }
                }
            }
        }

        return 0;
    }
};