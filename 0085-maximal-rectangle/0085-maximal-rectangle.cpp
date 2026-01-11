class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int>st;
        int maxArea = 0;
        
        int n = heights.size();

        for(int i = 0; i <= n; i++) 
        {
            int currHeight = (i == n) ? 0 : heights[i];

            while(!st.empty() && currHeight < heights[st.top()]) 
            {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int ans = 0;

        for(int i = 0; i < rows; i++) 
        {
            for(int j = 0; j < cols; j++) 
            {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};
