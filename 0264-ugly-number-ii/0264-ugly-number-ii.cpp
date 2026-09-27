class Solution {
public:
    int nthUglyNumber(int n) {

        if(n==1) 
          return 1;

        priority_queue<long long,vector<long long>, greater<long long> >pq;  
        unordered_set<long long>visited;

        pq.push(1);
        visited.insert(1);

        long long ans = 1;
        
        for(int i=0; i<n; i++)
        {
            ans = pq.top();
            pq.pop();

            if(!visited.count( ans*2 ))
            {
                pq.push(ans*2);
                visited.insert(ans*2);
            }
            if(!visited.count( ans*3 ))
            {
                pq.push(ans*3);
                visited.insert(ans*3);
            }
            if(!visited.count( ans*5 ))
            {
                pq.push(ans*5);
                visited.insert(ans*5);
            }
        }

        return ans;
    }
};