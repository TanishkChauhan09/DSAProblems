class Solution {
public:
     

    // TOPOSORT

    vector<int> toposort(vector<vector<int>>&adj,vector<int>&indegree)
    {
        queue<int>q;

        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int>ans;

        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(int j=0;j<adj[node].size();j++)
            {
                int neigh = adj[node][j];
                indegree[neigh]--;

                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
        
        vector<int>temp;

        return ans.size()==indegree.size()? ans: temp;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<vector<int>>adj1(k);
        vector<vector<int>>adj2(k);

        vector<int>indegree1(k,0);
        vector<int>indegree2(k,0);

        for(int i=0;i<rowConditions.size();i++)
        {
            int u = rowConditions[i][0]-1;
            int v = rowConditions[i][1]-1;
            
            adj1[u].push_back(v);
            indegree1[v]++;
        }
        for(int i=0;i<colConditions.size();i++)
        {
            int u = colConditions[i][0]-1;
            int v = colConditions[i][1]-1;
            
            adj2[u].push_back(v);
            indegree2[v]++;
        }
        
        vector<int>topo1 = toposort(adj1,indegree1);  // tells us that in which row the element will come by finding the toposort of row conditions
        vector<int>topo2 = toposort(adj2,indegree2); // tells us that in which col that element will come by finding the toposort of column conditions

        if(topo1.size()==0 || topo2.size()==0)
        {
            return {};
        }

        vector<vector<int>>ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++) 
        {
            for(int j=0;j<k;j++)
            {
                if(topo1[i]==topo2[j])
                {
                    ans[i][j] = topo1[i]+1;   // or topo2[j]+1; +1 isiliye kiya kyuki maine 1 indexing ko 0 indexing me conver kr kiya tha for making adjacency list
                }
            }
        }   

        return ans;  
    }
};