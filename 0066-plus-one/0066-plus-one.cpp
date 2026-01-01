class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int n = digits.size();

        //here, I am starting from last digit
        for (int i = n - 1; i >= 0; i--)
         {
            if (digits[i] < 9)
            {
                digits[i]++;      //this is just simple increment
                return digits;
            }
            digits[i] = 0;        // when digit was 9, make it 0 and carry forward
        }

        // if all digits were 9 then,
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
