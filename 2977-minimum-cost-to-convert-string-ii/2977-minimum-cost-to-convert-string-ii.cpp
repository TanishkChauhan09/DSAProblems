class Solution {
public:  

   // Recursion(D.P) + graph question

   typedef long long LL;
    
    unordered_map<string, vector<pair<string,LL>>>adj;
    set<LL>length;

    vector<LL>dpMemo;    // Recursion ko toh memoization krna hi hai kyuki recusrion me overlapping case arise ho skte hai
    unordered_map<string, unordered_map<string, LL>> dijkstraMemo;   // dijkstra algoritm ko bhi memoize kr diya hai 

    LL dijkstra(string src, string dest)
    {
        if(dijkstraMemo[src].count(dest))
        return dijkstraMemo[src][dest];

        priority_queue<pair<LL,string>,vector<pair<LL,string>>,greater<pair<LL,string>>> pq;
        pq.push({0,src});

        unordered_map<string ,LL> dist;
        dist[src] = 0;

        while(!pq.empty())
        {
            LL distance = pq.top().first;
            string str = pq.top().second;
            pq.pop();

            if(str == dest)
             return dijkstraMemo[src][dest] = distance;

            if(distance > dist[str])
            continue; 

            for(auto &edge : adj[str])
            {
                string neigh = edge.first;
                LL wt = edge.second;
                 
                // map me agr jisko me distance dene waala hoon who hoga hi nhi toh uss case me dist[neigh] mujhe 0 dete hai toh usi ka use krlenge ke agr wo hua nhi toh usse bhi distance dedo ushi mini hone waali hai aur agr hua toh uske liye toh check kr hi rhe hai 
                if(!dist.count(neigh) || ( distance + wt < dist[neigh]) )
                {
                    dist[neigh] = distance + wt;
                    pq.push({dist[neigh] , neigh});
                }
            }
        }  
         
        return dijkstraMemo[src][dest] = LLONG_MAX; 
    }
    
    LL find(int idx,int srcSize,string source,string target)
    {
        if(idx >= srcSize)
        {
            return 0;
        }

        if(dpMemo[idx] != -1)
         return dpMemo[idx];
        
        LL cost = LLONG_MAX;

        if(source[idx] == target[idx])
          cost = find(idx+1, srcSize, source, target);

        for(auto len : length)
        {
            if(idx+len > srcSize)
              break;

            string SRCsubstr = source.substr(idx, len);    // substr(index, length) ,length exclusive hoti hai
            string TARGETsubstr = target.substr(idx, len);

            // check krlo ke kya SRCsubstr se koi edge jaai bhi rhi hai ya nhi means conversion possible bhi hai ya nhi , aur ye hmm check krlenge adjacency list me hi ke kya koi is naam ka node hai bhi ya nhi  ayr nhi hai toh aage ki lengths pr substrng check kro means continue kr jaayenge
            if(!adj.count(SRCsubstr))
            {
                continue;
            }

            LL minLength =  LLONG_MAX;
            minLength = dijkstra(SRCsubstr, TARGETsubstr);

            // agr SRCsubstr ko TARGETsubstr me convert hi nhi kr paaya toh uss case me bhi aage ki lengths ke liye dekhenge
            if(minLength == LLONG_MAX)
            continue;

            LL furtherSol =  find(idx+len,srcSize,source,target);  // agr src se dest ke liye distance mil jaati hia toh aage waale ko convert krke dekhenge and ye bhi check kr lenge kya aage wala convert hya bhi hai ya nhi

            if(furtherSol == LLONG_MAX)
            continue;

            cost = min( cost , minLength + furtherSol);
        }  

       return dpMemo[idx] = cost;

    }

    long long minimumCost(string source,string target, vector<string>& original,vector<string>& changed, vector<int>& cost )
    {
        int n = original.size();
        int m = source.size();
        // unordered_map<string, vector<string>>adj;   // global define krlenge

        dpMemo.resize(m,-1);

        for(int i=0;i<n;i++)
        {
            string u = original[i];
            string v = changed[i];
            int wt = cost[i];

            adj[u].push_back({v,wt});  // conversion directed hoti hai isiliye directed graph bnaaya hai
        }

        // set<int>length;    // global define kr lenge
        for(int i=0; i<n; i++)
        {
            string temp = original[i];
            length.insert(temp.size());  // jiss length ki string convert kr skte hai sirf whi length leli hai
        }

        LL result = find(0,source.size(),source,target);

        return result == LLONG_MAX? -1: result;
    }
};