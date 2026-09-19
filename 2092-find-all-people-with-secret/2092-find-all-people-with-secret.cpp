class Solution {
public:

    // ALGORITHM TO SOLVE QUESTION
    
    // using the bfs

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        unordered_map<int,vector<pair<int,int>>>adj;// vector<vector<pair<int,int>>> adj(n); 

        // making the adjacency list
        for(int i=0;i<meetings.size();i++)
        {
            int person1 = meetings[i][0];
            int person2 = meetings[i][1];
            int timeformeeting = meetings[i][2];

            adj[person1].push_back({person2,timeformeeting});
            adj[person2].push_back({person1,timeformeeting});
        }

        vector<int>timeToKnowSecret(n,INT_MAX);
        timeToKnowSecret[0]=0;
        timeToKnowSecret[firstPerson]=0;

        queue<pair<int,int>>q;  // {person,meetingtime of knowing the secret}
        q.push({0,0});
        q.push({firstPerson,0});

        while(!q.empty())
        {
            int person1 = q.front().first;
            int timeOfKnowingSecretByPerson1 = q.front().second;
            q.pop();

            if(timeOfKnowingSecretByPerson1>timeToKnowSecret[person1])
              continue;

            
            for(int j=0;j<adj[person1].size();j++)
            {
                int person2 = adj[person1][j].first;  // person1 ki kis person2 ke saath meeting hai
                int meetingtimeWithOtherPerson = adj[person1][j].second ;  // person1 ki person 2 ke saath kitne bje meeting hai

        // meeting time se phle ya ussi time secret jaan paayega tbhi toh dusre person ko bta paayega
                if(timeOfKnowingSecretByPerson1 <= meetingtimeWithOtherPerson  && timeToKnowSecret[person2]>meetingtimeWithOtherPerson) // agr person2 already secret jaanta hai kya kahin aue kmm time me jaan paayega
                {
                     timeToKnowSecret[person2] = meetingtimeWithOtherPerson;
                     q.push({person2,meetingtimeWithOtherPerson});
                }
            }
        }


        // collect result
        vector<int> ans;
        for (int i = 0; i < n; i++) 
        {
            if(timeToKnowSecret[i]!=INT_MAX)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
