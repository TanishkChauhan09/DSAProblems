class Solution {
public:
    

    vector<int> toposort(unordered_map<int,vector<int>>&adj,vector<int>&indegree)
    {
        queue<int>q;

        for(int i=0;i<indegree.size();i++)
        {
            if(!indegree[i])
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

            for(int neigh:adj[node])
            {
                indegree[neigh]--;

                if(!indegree[neigh])
                {
                    q.push(neigh);
                }
            }
        }

        return ans.size()==adj.size() ? ans : vector<int>();
    }


    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // the one who did not have any group let's give them groups initally
        for(int i=0;i<n;i++)
        {
            if(group[i]==-1)
            {
                group[i] = m++;
            }
        }

        unordered_map<int,vector<int>>itemgraph;
        vector<int>itemindegree(n,0);

        for(int i=0;i<n;i++)
        {
            itemgraph[i] = vector<int>();
        }

        unordered_map<int,vector<int>>groupgraph;
        vector<int>groupindegree(m,0);

        for(int i=0;i<m;i++)
        {
             groupgraph[i] = vector<int>();
        }


        // to find totpo sort of items and groups let's make the adj list for that
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<beforeItems[i].size();j++)
            {
                int prev = beforeItems[i][j];
                itemgraph[prev].push_back(i);
                itemindegree[i]++;
                
                // for group topo sort's adjacency list
                if(group[i]!=group[prev])
                {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];

                    groupgraph[prevItemGroup].push_back(currItemGroup);
                    groupindegree[currItemGroup]++;
                }
                
            }
        }

        vector<int> itemorder = toposort(itemgraph,itemindegree);
        vector<int> grouporder = toposort(groupgraph,groupindegree);


        unordered_map<int,vector<int>>groupToItemInOrder;

       for(int i=0;i<itemorder.size();i++)
       {
            int item = itemorder[i];
            int itemgroup = group[item];

            groupToItemInOrder[itemgroup].push_back(item);

       }
          
       vector<int>result;

       for(int i=0;i<grouporder.size();i++)
       {
           int group = grouporder[i];

           for(int itemAtGroup : groupToItemInOrder[group])
           {
               result.push_back(itemAtGroup);
           }
       }

         return result;
    }
};







