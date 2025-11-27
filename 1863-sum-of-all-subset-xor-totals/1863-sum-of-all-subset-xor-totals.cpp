class Solution {
public:
    
    void find(int index,vector<int>&arr,int &result,int XOR)
    {
        if(index==arr.size())
        {
            result+=XOR;
            return;
        }

        find(index+1,arr,result,XOR);
        find(index+1,arr,result,XOR^arr[index]);
    } 

    int subsetXORSum(vector<int>& arr) {
        
        int n = arr.size();
        int result=0, XOR=0;

        find(0,arr,result,XOR);

        return result;
    }
};