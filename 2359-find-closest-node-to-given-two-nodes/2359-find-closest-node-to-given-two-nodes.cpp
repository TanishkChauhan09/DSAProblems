class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
       int n = edges.size();
       queue<int>q1;
       q1.push(node1);
       vector<int>dist1(n,-1);
       dist1[node1]=0;

       while(!q1.empty())
       {
            int node = q1.front();
            q1.pop();
            int neighbour = edges[node];
            if(neighbour!=-1)
            {
                if(dist1[neighbour]==-1)
                {
                    dist1[neighbour] = dist1[node]+1;
                    q1.push(neighbour);
                }
            }
       }

       queue<int>q2;
       q2.push(node2);
       vector<int>dist2(n,-1);
       dist2[node2]=0;

       while(!q2.empty())
       {
            int node = q2.front();
            q2.pop();
            int neighbour = edges[node];
            if(neighbour!=-1)
            {
                if(dist2[neighbour]==-1)
                {
                    dist2[neighbour] = dist2[node]+1;
                    q2.push(neighbour);
                }
            }
       }

       int mindist = INT_MAX;
       int minnode=-1;

       for(int i=0;i<n;i++)
       {
         if(dist1[i]!=-1 && dist2[i]!=-1)
         {
            int possdistreach = max(dist2[i],dist1[i]);
            if(mindist>possdistreach)
            {
                mindist = possdistreach;
                minnode = i;
            }
         }
       }

       return minnode;
    }
};