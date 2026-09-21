class Solution {
public:

    // 2D array elements to represent in 1D array fot its index in 1D array
    // [i][j] in 2D == [i*columns+j] in 1D
   
    // Using DSU

    class DSU
    {
        vector<int>parent;
        vector<int>size;

        public:
          
          DSU(int n)
          {
            parent.resize(n);
            size.resize(n);

            for(int i=0;i<n;i++)  // Initialise the parent
            {
                parent[i] = i;
            }
          }

          int findparent(int u)
          {
               if(u==parent[u])
               return u;
               // path compression
               return parent[u] = findparent(parent[u]);
          }

          void Union(int u,int v)
          {
                int Pu = findparent(u);
                int Pv = findparent(v);

                if(Pu==Pv)
                return;

                if(size[Pu]>size[Pv])
                {
                    parent[Pv] = Pu;
                    size[Pu] = size[Pu] + size[Pv];
                }
                else
                {
                    parent[Pu] = Pv; 
                    size[Pv] = size[Pv] + size[Pu];
                }
          }

          void set_size_Array(int idx,int value)
          {
                size[idx] = value;
          }

          int getResult()
          {
                return *max_element(size.begin(), size.end());
          }

    };


    int findMaxFish(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int totalSize = n*m;

        int drow[4] = {0,0,-1,1};
        int dcol[4] = {1,-1,0,0};
        
        DSU dsu(totalSize);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] > 0)
                {
                    int idx = i*m + j;
                    dsu.set_size_Array(idx,grid[i][j]);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] > 0)
                {
                    int idx = i*m + j; // getting the index of 2D in 1D array (Parent)

                    // will be looking in all 4 directions for fish count ti make the group of those with the parent
                    for(int k=0;k<4;k++)
                    {
                        int n_row = i + drow[k];
                        int n_col = j + dcol[k];
                        // check whether these new row and col is valid or not  AUR NYE ROW COL PR WATER BHI TOH HONA CHAHIYE TOH USKE LIYE WRITE : grid[n_row][n_col] > 0
                        if(n_row>=0 && n_row<n && n_col>=0 && n_col<m && grid[n_row][n_col]>0)
                        {
                            int neigh_idx = n_row*m + n_col;
                            dsu.Union(idx,neigh_idx);
                        }
                    }
                }
            }
        }
      
       return dsu.getResult();
 
    }
};