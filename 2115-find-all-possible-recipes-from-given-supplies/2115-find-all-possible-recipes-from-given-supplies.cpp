class Solution {
public:
    
    // yahan dhyaan de toh dependency dekh rhi hai ke jiss recipe ke sbhi ingredients milge phle wo bnegi anf uske baad wo bnenge jisme ye recipe indgredients ki tarah use ho rhi hogi toh dependency dikh thi hai isliye TOPO SORT(KAHN'S ALGORITHM) lga denge isme bnn main task adjacency list bnaane ka hai

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        int n = recipes.size();

        unordered_set<string>st(supplies.begin(),supplies.end());

        vector<int>visited(n,0);
        vector<string>result;

        unordered_map<string,vector<int>> adj;
        vector<int>indegree(n,0);

        // making the adjacency list
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<ingredients[i].size();j++) // recipe ke ingredients pr traverse krna
            {
                string ingredientOfRecipe = ingredients[i][j];
                if(st.find(ingredientOfRecipe) == st.end()) // agr recipe ka ingredient supplier me hua hi nhi toh    ingredients---> recipe  edge bnaa denge  means recipe bnaane se phle ye ingredient chahiye hoga supplier me 
                {
                    adj[ingredientOfRecipe].push_back(i);
                    indegree[i]++;     // u--->i edge
                }
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int idx = q.front();  // jo recipe kisi pe depent nhi hogi uski indegree me 0 hoga toh usi ka index bahar aayega
            q.pop();

            string recipe = recipes[idx];   // uss index pe konsi recipe hai wo nikaal lenge
            result.push_back(recipe);       // uss recipe ko result me daal denge

            for(auto it : adj[recipe])   // uss resipe pe jo jo index ki recipe dependent thi unki indegree ek se kmm krdenge and jo recipe ab kisi bhi ingredient pe depend nhi hogi usk iindegree 0 bnn chuki hogi and ussse bhi queue me daal denge ans me lene ke liye
            {
                int neigh = it;
                indegree[neigh]--;

                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }

        return result;

    }
};