class Solution {
public:

  // ab dono ke liye ek hi function dfs likhenge

  //iss problem me tree2 ke liye : isss particular problem mein baar-baar DFS call karne ki zarurat nahi hai. Yahi main point hai.

  void dfs(int node,vector<vector<int>>&adj,int count,vector<int>&visited,vector<int>&position)
  {
       visited[node] = 1;
       position[node] = count;

        // traversing the neighbours
        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];
            
            if(!visited[neigh])
            {
                dfs(neigh,adj,(count+1)%2,visited,position);  // (count+1)%2 , 0 hoga toh 1 bna dega aur agr 1 hoga toh 0 bna dega
            }
        }

  }



    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        int n1 = edges1.size()+1;
        vector<vector<int>>adj1(n1);

        for(int i=0;i<edges1.size();i++)
        {
            int u = edges1[i][0];
            int v = edges1[i][1];

            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        int n2 = edges2.size()+1;
        vector<vector<int>>adj2(n2);

        for(int i=0;i<edges2.size();i++)
        {
            int u = edges2[i][0];
            int v = edges2[i][1];

            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
       
        int count1 = 0;
        int count2 = 0;
        vector<int>position2(n2,0);
        vector<int>visited2(n2,0);

        dfs(0,adj2,0,visited2,position2);

        for(int i=0;i<n2;i++)
        {
            if((position2[i] %2)==0)
            count1++;
            else
            count2++;
        }

        int ans = max(count1,count2);

        vector<int>position1(n1,0);
        vector<int>visited1(n1,0);
        vector<int>result(n1,0);

        dfs(0,adj1,0,visited1,position1);

        // phle position1 vector me se jitne odd ya even hai wo count kr lenge
        int even = 0;
        int odd = 0;

        for(int i=0; i<n1; i++)
        {
            if(position1[i] == 0)
                even++;
            else
                odd++;
        }
        
         // jahan jahan 0 hai waha even daal denge wrna odd
        for(int i=0; i<n1; i++)
        {
            if(position1[i] == 0)
                result[i] = even;
            else
                result[i] = odd;
        }

       vector<int> finalans(n1,0);
       for(int i=0;i<n1;i++)
       {
            finalans[i] = result[i] + ans;
       }

       return finalans;
        
    }
};