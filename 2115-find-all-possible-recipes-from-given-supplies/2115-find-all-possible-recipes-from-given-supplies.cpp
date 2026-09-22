class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        int n = recipes.size();

        unordered_set<string>st(supplies.begin(),supplies.end());

        vector<int>visited(n,0);
        vector<string>result;

        // Time comp( n*n*ingrediesnts[i].size() = n*n*m)

        for(int i=0;i<n;i++)  // koi string kisi ki need ke baad bngyi toh fir unko doobara bnn ne ke liye mika dene ke liye ye loop chalaaya hai
        {
            for(int j=0;j<n;j++)
            {
                if(visited[j]==1)
                continue;

                bool flag=1;

                for(int k=0;k<ingredients[j].size();k++)
                {
                    if(st.find(ingredients[j][k]) == st.end())
                    {
                        flag=0;
                        break;
                    }
                }

                if(flag)
                {
                    visited[j] = 1;   // ye recipe bnn gyi hai donnara nhi bnaani ab isiliye iss index waali recipe ko visited mark kr diya hai
                    result.push_back(recipes[j]);  // ye recipe bngyi to isse result me daal do
                    st.insert(recipes[j]);  // ab ye recipe kisi aur recipe ke ingredients me aa skti hai toh isko me supplies me daal denge kyuki ab ye khud ready hai toh dusre kisi ka ingredients bnn skti hai
                }
            }
        }
        
        return result;
    }
};