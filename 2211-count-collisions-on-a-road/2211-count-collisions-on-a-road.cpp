class Solution {
public:
    int countCollisions(string directions) {
        
        int n = directions.size();
        stack<char>st;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(directions[i]=='S')
            {
                while(!st.empty() && st.top()=='R')
                {
                    st.pop();
                    ans+=1;
                }
                st.push('S');
            }
            else if(directions[i]=='R')
            {
                st.push('R');
            }
            else
            {
                bool firstCollision = 0;
                while(!st.empty() && st.top()=='R')
                {
                   if(!firstCollision) 
                   {
                        ans+=2;
                        st.pop();
                        firstCollision = 1;
                   }
                   else
                   {
                        ans+=1;
                        st.pop();
                        firstCollision = 1;
                   }
                }

                if(firstCollision)
                st.push('S'); 

                else if(!st.empty() && st.top()=='S')
                {
                   ans+=1;
                }
                else
                {
                    st.push('L');
                }
            }
        }

        return ans;
    }
};