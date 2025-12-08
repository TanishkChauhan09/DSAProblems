class Solution {
public:
    int countTriples(int n) {
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int ch = (i*i)+(j*j);
                int sqr = sqrt(ch);

                if(sqr<=n && sqr*sqr==ch)
                ans++;
            }            
        }

        return ans;
    }
};