class Solution {
public:
    
    // brute force and slow
    
    int mod = 1e9+7;

    int specialTriplets(vector<int>& arr) {
        
        int n = arr.size();

        long long count=0;

        unordered_map<long long,long long>left;
        unordered_map<long long,long long>mp_all;

        for(int i=0;i<n;i++)
        {
            mp_all[arr[i]]++;
        }

        for(int i=0;i<n-1;i++)
        {
           long long mul = arr[i]*2;
           long long lrr=0;
           mp_all[arr[i]]--;

           if(left.find(mul)!=left.end())
           {
               lrr = left[mul];
           }
           long long rr=0;
           if(mp_all.find(mul)!=mp_all.end())
           {
               rr = mp_all[mul];
           }
           left[arr[i]]++;
           count = (count%mod+((lrr%mod)*(rr%mod))%mod)%mod;
        }

        return (int)count%mod;

    }
};