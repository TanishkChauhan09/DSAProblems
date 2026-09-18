class Solution {
public:
    
    int components;

    int find(int u,vector<int>&parent)
    {
        if(u==parent[u])
        return u;

        return parent[u] = find(parent[u],parent);
    }

    bool Union(int prnt,int child,vector<int>&parent)
    {
        // jo child apne parent se connect hone aaya hai wo already kisi aur ka child na ho means uska uske sivaaye koi parent nhi hona chahiye agr hua toh tree property break hojaayegi
        if(find(child,parent)!=child)  
        return 0;

         // cycle exisit kregi agr hmne ye edge connect krdi isiliye return 0 kyuki tree me cycle nhi hodkti
         if(find(prnt,parent)==child)
         return 0;

         parent[child] = prnt;
         components--;

         return 1;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        vector<int>parent(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        components=n;

        for(int i=0;i<n;i++)
        {
            int node = i;
            int left_Child = leftChild[i];
            int right_Child = rightChild[i];

            if(left_Child!=-1 && Union(node,left_Child,parent)==0)
            return 0;

            if(right_Child!=-1 && Union(node,right_Child,parent)==0)
            return 0;
        }
     
        if(components==1)
        return 1;

        return 0;
        
    }
};