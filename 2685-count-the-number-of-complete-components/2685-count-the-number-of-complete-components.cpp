class Solution {
public:
    
    // By using DSU (Union by size kyuki isme hme ek component me kitne vertices hai wo chahiye jo sirf size se union krne pr possible hoskta hai)


    // if there are n vertices in a graph then there must be nC2 edges which is n(n-1)/2 .

    int findparent(int u,vector<int>&parent)
    {
        if(u==parent[u])
        return u;

        return parent[u] = findparent(parent[u],parent);
    }

    void unionbysize(int u,int v,vector<int>&parent,vector<int>&size)
    {
        int Pu = findparent(u,parent);
        int Pv = findparent(v,parent);

        if(Pu==Pv)
        return;

        if(size[Pu]>size[Pv])
        {
            parent[Pv] = Pu;
            size[Pu] += size[Pv];
        }
        else 
        {
            parent[Pu] = Pv;
            size[Pv] += size[Pu];
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<int>parent(n,0);
        vector<int>size(n,0);
        
        for(int i=0;i<n;i++) // initially all will be seperate components
        {
            parent[i] =i;
            size[i] = 1;   // size ko initially 1 lena hoga sbhi ke liye adge 0 lenge toh 0+0 kuch nhi aayega bss 0 hi rhta isiliye taaki sum increase hopaaye unionbysize function me
        }

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            unionbysize(u,v,parent,size);
        }
 
       // now count the number of edges for each component
       unordered_map<int,int>mp;
       for(int i=0;i<edges.size();i++)
       { 
           int u = edges[i][0];

           int prnt = findparent(u,parent);  // hrr wo edge jo ek hi component ka part hongi same hi parent me jaakr add kregi jiss se hme pta chal jayegi ke jiss poore component ka Ultimate parent hai usme kitni edge hone waali hai
           mp[prnt]++;  
       }

       // finding the ans
       int ans=0;

       for(int i=0;i<n;i++)
       {
           if( findparent(i,parent) == i )
           { 
               int vertices = size[i];  // uss component ki vertices size array me hongi
               int edges = mp[i];  // edges hmne phle hi uss parent ke respective, map me count kr rkhi hai

               if( ( vertices*(vertices-1)/2 ) ==  edges )
                 ans++;
           }
       }

       return ans;

    }    
};