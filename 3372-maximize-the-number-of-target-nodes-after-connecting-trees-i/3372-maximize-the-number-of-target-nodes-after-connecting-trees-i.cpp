class Solution {
public:

    // Algorithm to solve this
    
    // maine socha ke hmm apne tree1 ke nodes ko tree2 ke uss node se connect krenge jiss ki indegree sbse jyada hai kyuki kmm 'k' ki valye ke liye whi apne aaas paas ke sbse jyada node laake de skte hai toh isliye maine sbse phle tree2 ke maximum indegree wale se bfs call kreke 'k-1' distance me jitne node milenge utne phle hi count krlo 'k-1' isiliye kyuki ek edge tree1 se tree2 ke liye bhi toh aayegi 

    // fir tree1 se k me jitne nodes pr jaa skta hoon unka bhi count nikaal liya and then fir hrr ek me tree2 se jo k-1 me nodesCount nikaala tha bss wo add krdenge

//Counterexample  : MERI APPROACH ME MISTAKE HAI 

// Maan lo Tree 2:

//           0
//           |
//           1
//        /  |  \
//       2   3   4
//                |
//                5
//                |
//                6

// Agar k-1 = 2 hai:

// Node 1 ka degree = 4 → maximum degree
// Lekin 2 distance mein nodes:
// 1
// 0,2,3,4
// 5
// → total 6

// Kisi aur structure mein lower-degree node ka second-level subtree zyada ho sakta hai. Isliye degree ko maximize karna aur radius k-1 ke andar nodes ko maximize karna same cheez nahi hai.  KYUKI YAHAN PR 4 WALA APNI AAS PAAS KI DISTANCE 2 ME SBSE JYADA countNodes dega

  // TOH ISKA SOLUTION YHI HAI KE HMM TREE2 KE SBHI NODES SE 'K-1' DISTANCE ME SE MAXIMUM NODESCOUNT LE AAYE 
    
    int bfs(int node,vector<vector<int>>&adj,int k)
    {
        int n = adj.size();
        vector<int>visited(n,0);
        queue<int>q;
        q.push(node);

        int countNodes = 0;

        while(!q.empty() && k>=0)
        {
            int size = q.size();

            while(size--)
            {
                int node = q.front();
                q.pop();
                visited[node] = 1;
                countNodes++;

                for(int j=0;j<adj[node].size();j++)
                {
                    int neigh = adj[node][j];
                    if(!visited[neigh])
                    {
                        q.push(neigh);
                    }
                }
            }
            k--;
        }
        return countNodes;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
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
       
        int ans = 0;
        
        for(int i=0;i<n2;i++)
        {
            int anotherTreeconnectedNodes = bfs(i,adj2,k-1);
            ans = max(ans, anotherTreeconnectedNodes);
        }

        vector<int>result(n1,0);

        for(int i=0;i<n1;i++)
        {
            int size = bfs(i,adj1,k);
            size += ans;
            result[i] += size;
        }

        return result;
    }
};