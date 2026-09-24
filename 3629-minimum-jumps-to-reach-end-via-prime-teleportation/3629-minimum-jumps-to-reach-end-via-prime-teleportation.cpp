class Solution {
public:

    // BFS kyuki hme ek step me jahan jaa sjkta hoon wo sb ek baar me eliminate krne the , isliye unko ek saath queue me daal diya and saare ek saath process kre and queue use kiya toh BFS bhi aayega
    
    vector<int>isPrime;
    unordered_map<int, vector<int>>mp;

    void sieveOfEratosthenes(int maxEle)
    {
        isPrime.resize(maxEle+1,1);  // maxEle+ 1 kra hai kyuki maxEle bhi chahiye vector ke index pr
        isPrime[0] = 0;
        isPrime[1] = 0;

        for(int i=2; i*i<=maxEle; i++)
        {
            if(isPrime[i])
            {
                for(int mul = i*i ; mul <= maxEle; mul += i)
                {
                    isPrime[mul] = 0;
                }
            }
        }
      
    }

    int minJumps(vector<int>& nums) {
          
        int n = nums.size();
        int maxEle = 0;
        // array ke sbhi elements ko hmne unke indexed se map kra diya hai
        for(int i=0; i<n; i++)
        {
            mp[nums[i]].push_back(i);
            maxEle = max(maxEle, nums[i]);
        }
 
        sieveOfEratosthenes(maxEle);

        queue<int>q;
        vector<int>visited(n,0);
        q.push(0);
        visited[0] = 1;
        int steps = 0;

        unordered_set<int>seen;

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int idx = q.front();
                q.pop();

                if(idx == n-1)
                  return steps;

                if(idx-1 >= 0 && !visited[idx-1])
                {
                    q.push(idx-1);
                    visited[idx-1] = 1;
                }  
                if(idx+1 <=n-1 && !visited[idx+1])
                {
                    q.push(idx+1);
                    visited[idx+1] = 1;
                }  

                if(!isPrime[nums[idx]] || seen.count(nums[idx]))  // agr wo number already prime ki wajah se dekh rkha hai ya nhi
                 continue;

                for(int mul = nums[idx]; mul<=maxEle; mul+=nums[idx])
                {
                    if(!mp.count(mul))
                        continue;

                    for(int indexes : mp[mul]) 
                    {
                        if(!visited[indexes])
                        {
                            visited[indexes] = 1;
                            q.push(indexes);
                        }
                    }   
                } 
                seen.insert(nums[idx]);
            }
            steps++;
        }

        return steps;
    }
};