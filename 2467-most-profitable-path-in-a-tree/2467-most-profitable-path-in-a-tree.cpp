class Solution {
public:

    // INSIGHTS
    // ye undirected tree diya hua hai means ye connected toh hoga iske koi aur components nhi honge and isme koi cycle bhi nhi hogi which simply means JO BHUT IMPORTANT BHI HAI KE EK NODE SE DUSRE NODE PR JAANE KA SIRF EK HI PATH/WAY/RAASTA HOGA

    // jaise isme Bob , BobNode se 0 tk sirf ek hi path se jaa paayega jisse ke hmm alice ka maximum profit nikaal paayege kyuki Bob ka path toh fix hogya na 0 tk

    bool DFSBob(int currnode,vector<vector<int>>&adj,vector<int>&visited,unordered_map<int,int>&mp,int time)
    {
        visited[currnode] = 1;
        mp[currnode] = time;

        if(currnode == 0)
        return 1;

        // going on neighbours to see whether i can reach to 0 or not
        for(int j=0;j<adj[currnode].size();j++)
        {
            int neigh = adj[currnode][j];
            if(!visited[neigh])
            {
                if( DFSBob(neigh,adj,visited,mp,time+1) ) // taki kisi neighbour se agr 0 pr pahuch gya toh baaki ke aur neighbours pe naa jau
                return 1;
            }
        }

        mp.erase(currnode);
        return 0;
    }

    void DFSAlice(int node,vector<vector<int>>&adj,vector<int>&visited,unordered_map<int,int>&mp,vector<int>&amount,int currincome,int &ans,int time)
    {
        // agr bob uss path pe gya hi nhi toh fir bhi poora amount hi lena pdega and wo pta chal jaayega ke jispe bob nhi gya wo map me bhi hoga also chahe bob gya hi ho pr agr alice ka time kmm hai bob ke time se toh bhi poora amount hi lena pdega and bob ka time map me se mil jaayega
        if( mp.find(node)==mp.end() || time < mp[node] )  
        {
            currincome += amount[node];
        }
        // agr dodno k time same hua sirf tbhi half amount add krenge fir chahe amount positive ho ya fir negative
        else if( time == mp[node])
        {
            currincome += (amount[node]/2);
        }
        
        // leaf node pr aa gya hoon toh ans me update kr deta hoon pr haan agr adj[node].size()==1 aaya toh aisa ho ske hai ke wo starting wala hi ho tree ka  '' 0->1->2->3->4 '' isme 0 ki wajah se update nhi hona chahiye kyuki wo leaf hai hi nhi
        if(adj[node].size() == 1 && node!=0)
        {
            ans = max(ans,currincome);
        }

        visited[node]=1;

        // travering all neighbours for leaf nodes
        for(int j=0;j<adj[node].size();j++)
        {
            int neigh = adj[node][j];

            if(!visited[neigh])
            {
                DFSAlice(neigh,adj,visited,mp,amount,currincome,ans,time+1);
            }
        }


    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {

        int n = amount.size();
        vector<vector<int>>adj(n);
        // making the adjacency list
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int,int>mp;
        vector<int>visited(n,0);
        int t=0;
        
        // BOB ke liye DFS
        DFSBob(bob,adj,visited,mp,t);
        
        t=0;
        int ans=INT_MIN;
        int currincome=0;
        for(int i=0;i<n;i++)
        {
            visited[i] = 0;
        }
 
        // Alice ke liye DFS
        DFSAlice(0,adj,visited,mp,amount,currincome,ans,t);

        return ans;
        
    }
};