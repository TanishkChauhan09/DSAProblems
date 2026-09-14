class Solution {
public:

    int findparent(int u,vector<int>&parent)
    {
        if(u==parent[u])
        return u;

        return parent[u] = findparent(parent[u],parent);
    }

    void unionbyrank(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        int Pu = findparent(u,parent);
        int Pv = findparent(v,parent);

        if(Pu==Pv)
        return;

        if(rank[Pu]<rank[Pv])
        {
            parent[Pu] = Pv;
        }
        else if(rank[Pu]>rank[Pv])
        {
            parent[Pv] = Pu;
        }
        else
        {
            rank[Pu]++;
            parent[Pv] = Pu;
        }
    }

    
    bool similar(string &str1,string &str2)
    {
        int n = str1.size();
        int different = 0;

        for(int i=0;i<n;i++)
        {
            if(str1[i]!=str2[i])
            {
                different++;
            }
        }

        if(different==2)
        return 1;
        
        if(different==0)
        return 1;

        return 0;
    }

    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();

        vector<int>parent(n,0);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(similar(strs[i],strs[j]))
                {
                    unionbyrank(i,j,parent,rank);
                }
            }
        }

        int count=0;
        

        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
            {
                count++;
            }
        }

        return count;
    }
};