class Solution {
public:
    
    // DFS se

    int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,vector<int>&visited,unordered_set<int>&haveBoxButNotOpened)
    {
        //agr box se already candy nikaal li hai toh ab aur candies nhi lepaunga uss box se

        if(visited[box])
        return 0;

        //suppose box pr toh aaye aur agr wo open hi nhi hua toh ye bhi check krlenge aur usko hasBox me daal denge ke agr future me kahin kisi box me iski key milti hai toh iski bhi candies le lenge

        if(status[box]==0)
        {
            haveBoxButNotOpened.insert(box);
            return 0;
        }

        int candiesFromBox = candies[box];
        visited[box] = 1;

        // iss box ki candy toh leli ab is box me koi aur box hai ya nhi ye bhi dekh lenge

        
        for(int j=0;j<containedBoxes[box].size();j++)
        {
            int anotherBox = containedBoxes[box][j];
            candiesFromBox += dfs(anotherBox,status,candies,keys,containedBoxes,visited,haveBoxButNotOpened);
        }
        

        // ab jis box pr hai uske paas uss box ki key hai ya nhi jo box hmaare paas toh hai pr open nhi hai jisko hmne hasBox me rkha hua hai

        for(int i=0; i<keys[box].size();i++)
        {
            int keyOfBox = keys[box][i];

            // pshle uss box ka status 1(open) mark krdenge kyuki agr wo box kahin kisi ko aage future me milta hai toh direct uss box ko open kiya ja ske
            status[keyOfBox] = 1;

            // ab hmm ye bhi dekh lenge ke kahin wo key jo Box already hmaare paas hai unme se toh kisi box ki nhi hai

            if( haveBoxButNotOpened.find(keyOfBox) != haveBoxButNotOpened.end() )
            {
                candiesFromBox += dfs(keyOfBox,status,candies,keys,containedBoxes,visited,haveBoxButNotOpened);
            }
        }
        
        return candiesFromBox;

    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

     int n = status.size();

     int candiesCollected=0;
     vector<int>visited(n,0);
     unordered_set<int>haveBoxButNotOpened;

     for(int i=0;i<initialBoxes.size();i++)
     {
        int box = initialBoxes[i];
        candiesCollected += dfs(box,status,candies,keys,containedBoxes,visited,haveBoxButNotOpened);
     }

     return candiesCollected;
        
    }
};