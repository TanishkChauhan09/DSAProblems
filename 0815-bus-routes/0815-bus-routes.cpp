class Solution {
public:
   
    // parallely hi ek saath src jitne bhi bus ke stop me pdta hai sbhi se suru kr denge isiliye inilitially ek saath sbhi ko queue me push krdenge and jiss se bhi sbse phle target pr pahuch gya ye guaranteed hai ke whi mera minimum laakr bhi sbse phle hi dega
    
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {

        if(source==target)
        return 0;
        
        unordered_map<int,vector<int>>adjOfBus;
        
        for(int bus=0;bus<routes.size();bus++)
        {
            for(int j=0;j<routes[bus].size();j++)
            {
                int stops = routes[bus][j];
                adjOfBus[stops].push_back(bus);
            }
        }
        
        queue<int>q;
        vector<int>visited(routes.size());

        for(int i=0;i<adjOfBus[source].size();i++)
        {
            int bus = adjOfBus[source][i];

            q.push(bus);
            visited[bus] = 1;
            
        }

        int res=0;

        while(!q.empty())
        {
            int n = q.size();
            res++;
            
            while(n--)
            {
                int bus = q.front();
                q.pop();

                for(int j=0;j<routes[bus].size();j++)
                {
                    int stp = routes[bus][j];

                    if(stp==target)
                    {
                        return res;
                    }

                    for(int k=0;k<adjOfBus[stp].size();k++)
                    {
                        int bs = adjOfBus[stp][k];
                        if(!visited[bs])
                        {
                            visited[bs]=1;
                            q.push(bs);
                        }
                    }
                }
            }
        }

        return -1;

    }
};