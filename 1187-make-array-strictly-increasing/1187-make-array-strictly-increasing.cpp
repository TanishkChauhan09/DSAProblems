class Solution {
public:
    
    // Top-down / Memoization

    map< pair<int,int>, int> mp;

    // auto ptr = upper_bound(arr.begin(), arr.end(), element);  upper bound wala element se just greater element ka pointer/address laake deta hai and ye upper bound sorted array me kaam krta hai and index me convert krne ke liye : int idx = ptr - begin(arr);
    // pointer me se array ke begin ka index subtract krdenge

    int n;

    int find( int index, vector<int>&arr1, vector<int>&arr2, int prev)
    {
        // Base condition
        if(index >= n)
          return 0;

        if(mp.find({index,prev}) != mp.end())
         return mp[{index,prev}];  

        // agr current wala incresing toh yahan do choices lenge phla toh aage bdh jaayenge and dusra ye ke usko prev se just greater se replace krdenge

        int poss1 = INT_MAX, poss2 = INT_MAX ;

        if(arr1[index] > prev)
        {
            // this skip step is for already increasing arr1 till index
            poss1 = find(index+1, arr1, arr2, arr1[index]);
        }  
        
        auto upper = upper_bound( begin(arr2), end(arr2), prev);
        
        if(upper != end(arr2))
        {
            int idx = upper - begin(arr2);
            int possible =  find(index+1, arr1, arr2, arr2[idx]); // next index ke liye prev arr2[idx] wala element hoga and 1 operation yahan kiya isliye 1+ kiya hai

            if(possible != INT_MAX)
              poss2 = 1+possible;
        }

        return  mp[{index,prev}] =  min( poss1, poss2);
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        n = arr1.size();

        // don't forget to sort arr2 because upper_bound() use kr rhe hai jo sirf sorted array pe kaam krta hai

        sort(arr2.begin(), arr2.end());

        int res = find(0, arr1, arr2, INT_MIN);

        if(res == INT_MAX)
         return -1;

        return res; 
    }
};