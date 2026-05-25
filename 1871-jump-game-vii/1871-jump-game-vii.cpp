class Solution {
public:
   
    // this array question is going to solve using the bfs on indexes
    bool canReach(string s, int minJump, int maxJump) {
        
        int n = s.size();

        if(s[n-1]=='1')
        return 0;

        queue<int>q;
        q.push(0);
        
        for(int i=1; i<n; i++)
        {
            // i will only find ans or apply queue operations(bfs) when my current idx value is '0'
            if(s[i]=='0')
            {
                while(!q.empty() && q.front()<i-maxJump)
                q.pop();

                // if(q.empty())
                // return 0;

                int front = q.front();
                if(i>=front+minJump && i<=front+maxJump)
                {
                    if(i==n-1)
                    return 1;
                    q.push(i);
                }

            }
        }
        return 0;
    }
};