class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]++;
        }

        vector<int>result;
        for(int i=0;i<indegree.size();i++)
        {
            if(!indegree[i])
            result.push_back(i);
        }
        return result;
    }
};