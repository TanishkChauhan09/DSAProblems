class Solution {
public:
    
    int find(int i,int j,vector<int>&arr)
    {
        // Base condition
        if(i>j)
        return 0;

        // logic
        int first_pick = arr[i]+ min(find(i+1,j-1,arr),find(i+2,j,arr));

        int last_pick = arr[j]+ min(find(i+1,j-1,arr),find(i,j-2,arr));

        return max(first_pick,last_pick);
    }

    bool predictTheWinner(vector<int>& nums) {
        
        int n = nums.size();

        if(n==1)
        return 1;
        
        int first = find(0,n-1,nums);

        int second = min(find(0,n-2,nums),find(1,n-1,nums));

        if(first>=second)
        return 1;

        return 0;
    }
};