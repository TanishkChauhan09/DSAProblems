class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        long long totalApples = 0;
        
        //here,sum of all apples
        for (int x : apple) 
        {
            totalApples += x;
        }
        
        //sort capacities in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());
        
        // here i am picking boxes greedily
        int boxesUsed = 0;
        for (int cap : capacity) 
        {
            totalApples -= cap;
            boxesUsed++;
            
            if (totalApples <= 0)
                return boxesUsed;
        }
        
        return boxesUsed; 
    }
};