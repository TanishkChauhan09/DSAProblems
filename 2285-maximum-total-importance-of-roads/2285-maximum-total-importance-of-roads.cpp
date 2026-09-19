class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

        vector<long long>indegree(n,0);

        for(int i=0;i<roads.size();i++)
        {
            int u = roads[i][0];
            int v = roads[i][1];
            indegree[u]+=1;
            indegree[v]+=1;
        }
        sort(indegree.rbegin(),indegree.rend());  // sort in descending order , jbki jo normal sort wala hota hai wo ascending order me sort krta hai
        long long N = n;

        long long res=0;

        for(int i=0;i<n;i++)
        {
            res+=(indegree[i]*N);
            N--;
        }

        return res;
        
    }
};